#ifndef DRAW_SENDER_H_INCLUDED
#define DRAW_SENDER_H_INCLUDED

#include "timer.h"
#include "interface/frame.h"
#include "interface/sourceconfiguration.h"
#include "interface/sourceinterface.h"
#include "interface/daemonsourceinterface.h"
#include "stub/sourcedaemon.hpp"
#include "ipc-rpc/localsocket.h"
#include "ipc-rpc/pipeinterpreter.hpp"
#include "ipc-rpc/pipeinterpreterbase.hpp"
#include "core/color.h"
#include <string>
#include <mutex>
#include <memory>
#include <QObject>
#include <QColor>

class AnimInterface {
	public:
		virtual Frame nextFrame() = 0;
		virtual ~AnimInterface();
};

class AnimSender: public QObject, public SourceInterface {
	Q_OBJECT
	private:
		std::unique_ptr<LocalSocket> socket_;
		std::unique_ptr<PipeInterpreter<AnimSender, DaemonSourceInterface>> pipe_;
		SourceConfiguration config_;
		int id_;
		std::unique_ptr<AnimInterface> anim_;
		std::unique_ptr<Timer> timer_;
		std::mutex m_;
		void packetCallback();
	public:
		AnimSender(const std::string& socket_name);
		virtual ~AnimSender();
		const SourceConfiguration& getSourceConfiguration() const;
	public slots:
		void setAnim(AnimInterface* anim);
};

#endif
