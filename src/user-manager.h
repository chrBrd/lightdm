/*
 * Copyright (C) 2010 Robert Ancell.
 * Author: Robert Ancell <robert.ancell@canonical.com>
 * 
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#ifndef _USER_MANAGER_H_
#define _USER_MANAGER_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define USER_MANAGER_TYPE (user_manager_get_type())
#define USER_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), USER_MANAGER_TYPE, UserManager));

typedef struct UserManagerPrivate UserManagerPrivate;

typedef struct
{
    gchar *name;
    gchar *real_name;
    gchar *image;
    gchar *home_dir;
    gboolean logged_in;
} UserInfo;

typedef struct
{
    GObject         parent_instance;
    UserManagerPrivate *priv;
} UserManager;

typedef struct
{
    GObjectClass parent_class;
    void (*user_added)(UserManager *manager, UserInfo *user);
    void (*user_changed)(UserManager *manager, UserInfo *user);
    void (*user_removed)(UserManager *manager, UserInfo *user);
} UserManagerClass;

GType user_manager_get_type (void);

UserManager *user_manager_new (GKeyFile *config_file);

gint user_manager_get_num_users (UserManager *manager);

const UserInfo *user_manager_get_user (UserManager *manager, const gchar *username);

GList *user_manager_get_users (UserManager *manager);

gboolean user_manager_get_user_defaults (UserManager *manager, gchar *username, gchar **language, gchar **layout, gchar **session);

G_END_DECLS

#endif /* _USER_MANAGER_H_ */
