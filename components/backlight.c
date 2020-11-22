/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <string.h>

#include "../util.h"

#if defined(__linux__)
	#include <limits.h>
	#include <stdint.h>
	#include <unistd.h>

	const char *
		backlight_perc(const char *backlight)
		{
			float value;
			char path[PATH_MAX];

			if (esnprintf(path, sizeof(path),
				"/sys/class/backlight/%s/actual_brightness", backlight) < 0) {
				return NULL;
			}
			if (pscanf(path, "%f", &value) != 1) {
				return NULL;
			}

			return bprintf("%d", (int)(value / 255 * 100));
		}

#else
	const char *
		backlight_perc(const char *backlight)
		{
			return NULL;
		}

#endif
