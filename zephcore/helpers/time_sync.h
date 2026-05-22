/*
 * SPDX-License-Identifier: Apache-2.0
 * Joystick UI: track which source last set the RTC (System > Info > Time).
 */

#pragma once

#include <zephyr/sys/util.h>

#ifdef __cplusplus
extern "C" {
#endif

enum time_sync_source {
	TIME_SYNC_NONE = 0,
	TIME_SYNC_GPS,
	TIME_SYNC_APP,
	TIME_SYNC_WIFI,
	TIME_SYNC_CLI,
};

#if IS_ENABLED(CONFIG_ZEPHCORE_UI_DESIGN_JOYSTICK)

void time_sync_report(enum time_sync_source src);
const char *time_sync_display_label(void);

#else

static inline void time_sync_report(enum time_sync_source src)
{
	ARG_UNUSED(src);
}

#endif /* CONFIG_ZEPHCORE_UI_DESIGN_JOYSTICK */

#ifdef __cplusplus
}
#endif
