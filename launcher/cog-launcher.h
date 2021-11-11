/*
 * cog-launcher.h
 * Copyright (C) 2021 Igalia S.L.
 * Copyright (C) 2017 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include "../core/cog.h"

G_BEGIN_DECLS

#define COG_TYPE_LAUNCHER (cog_launcher_get_type())

G_DECLARE_FINAL_TYPE(CogLauncher, cog_launcher, COG, LAUNCHER, GApplication)

struct _CogLauncherClass {
    GApplicationClass parent_class;
};

typedef enum {
    COG_SESSION_REGULAR,
    COG_SESSION_AUTOMATED,
} CogSessionType;

CogLauncher *cog_launcher_get_default                  (void);
CogLauncher *cog_launcher_init_default(CogSessionType sessionType);
CogShell    *cog_launcher_get_shell                    (CogLauncher *launcher);
gboolean     cog_launcher_is_automated(CogLauncher *launcher);

void  cog_launcher_add_web_settings_option_entries     (CogLauncher *launcher);
void  cog_launcher_add_web_cookies_option_entries      (CogLauncher *launcher);
void  cog_launcher_add_web_permissions_option_entries  (CogLauncher *launcher);

G_END_DECLS