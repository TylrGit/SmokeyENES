#pragma once

struct Queue {
	int pos = 0;
	bool filled = false;
	double values[10] = {};

	// Return -1 if entire array not set
	// Else average
	int average() {
		if (!filled) return -1.0;

		double sum = 0.0;
		for (int i = 0; i < 10; i++) {
			sum += values[i];
		}

		return sum / 10;
	}

	void enque(double val) {
		values[pos] = val;
		pos = (pos + 1) % 10;
		if (pos == 0) filled = true;
	}
};
