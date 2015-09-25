#include "animsender.h"
#include "core/array2D.hpp"
#include <thread>
#include <cmath>
#include <QPoint>
#include <QDebug>

AnimInterface::~AnimInterface() {}

AnimSender::AnimSender(const std::string& socket_name): id_{0} {
	socket_ = std::unique_ptr<LocalSocket>{LocalSocket::create()};
	socket_->connectToServer(socket_name.c_str(), 1000);
	socket_->readTimeout(1000);
	socket_->writeTimeout(1000);
	pipe_ = std::unique_ptr<PipeInterpreter<AnimSender, DaemonSourceInterface>>{new PipeInterpreter<AnimSender, DaemonSourceInterface>{this, socket_.release()}};
	config_ = pipe_->getSourceConfiguration("Anim source");
	timer_ = std::unique_ptr<Timer>{new Timer(std::bind(&AnimSender::packetCallback, this), std::chrono::milliseconds((int) ceil(2000.0 / config_.framerate)))};
	timer_->start();
}

AnimSender::~AnimSender() {
	timer_->stop();
	pipe_->disconnect();
}

const SourceConfiguration& AnimSender::getSourceConfiguration() const {
	return config_;
}

void AnimSender::setAnim(AnimInterface* anim) {
	m_.lock();
	anim_ = std::unique_ptr<AnimInterface>{anim};
	m_.unlock();
}

void AnimSender::packetCallback() {
	if (anim_) {
		m_.lock();
		Frame f1, f2;
		f1 = anim_->nextFrame();
		f2 = anim_->nextFrame();
		m_.unlock();
		f1.id = id_++;
		f2.id = id_++;
		pipe_->sendFrame(f1, f2);
	}
}


