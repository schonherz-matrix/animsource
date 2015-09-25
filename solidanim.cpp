#include "solidanim.h"
#include "core/array2D.hpp"

SolidAnim::SolidAnim(const SourceConfiguration& configuration, const QColor& primary_color, const QColor& secondary_color, int num):
	primary_color_{Color{primary_color.red(), primary_color.green(), primary_color.blue()}},
	secondary_color_{Color{secondary_color.red(), secondary_color.green(), secondary_color.blue()}},
	fl_{num},
	cntr_{0},
	first_{true}
{
	f1_.pixels = Array2D<Color>{configuration.width, configuration.height};
	f2_.pixels = Array2D<Color>{configuration.width, configuration.height};
	for (int x = 0; x < configuration.width; x++) {
		for (int y = 0; y < configuration.height; y++) {
			f1_.pixels(x,y) = primary_color_;
			f2_.pixels(x,y) = secondary_color_;
		}
	}
}

Frame SolidAnim::nextFrame() {
	if (cntr_ == fl_) {
		if (first_) {
			first_ = false;
		} else {
			first_ = true;
		}
		cntr_ = 0;
	} else {
		cntr_++;
	}
	if (first_) {
		return f1_;
	} else {
		return f2_;
	}
}

