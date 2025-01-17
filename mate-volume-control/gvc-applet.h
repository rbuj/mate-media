/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 Red Hat, Inc.
 * Copyright (C) 2014 Michal Ratajsky <michal.ratajsky@gmail.com>
 * Copyright (C) 2019 Victor Kareh <vkareh@vkareh.net>
 * Copyright (C) 2014-2021 MATE Developers
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef __GVC_APPLET_H
#define __GVC_APPLET_H

#include <glib-object.h>
#include <glib.h>
#include <mate-panel-applet.h>

G_BEGIN_DECLS

#define GVC_APPLET_DBUS_NAME "org.mate.VolumeControlApplet"
#define APPLET_ICON "multimedia-volume-control"

#define GVC_TYPE_APPLET (gvc_applet_get_type())
#define GVC_APPLET(o) \
  (G_TYPE_CHECK_INSTANCE_CAST((o), GVC_TYPE_APPLET, GvcApplet))
#define GVC_APPLET_CLASS(k) \
  (G_TYPE_CHECK_CLASS_CAST((k), GVC_TYPE_APPLET, GvcAppletClass))
#define GVC_IS_APPLET(o) (G_TYPE_CHECK_INSTANCE_TYPE((o), GVC_TYPE_APPLET))
#define GVC_IS_APPLET_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE((k), GVC_TYPE_APPLET))
#define GVC_APPLET_GET_CLASS(o) \
  (G_TYPE_INSTANCE_GET_CLASS((o), GVC_TYPE_APPLET, GvcAppletClass))

typedef struct _GvcApplet GvcApplet;
typedef struct _GvcAppletClass GvcAppletClass;
typedef struct _GvcAppletPrivate GvcAppletPrivate;

struct _GvcApplet {
  GObject parent;
  GvcAppletPrivate *priv;
};

struct _GvcAppletClass {
  GObjectClass parent_class;
};

GType gvc_applet_get_type(void) G_GNUC_CONST;

GvcApplet *gvc_applet_new(void);
void gvc_applet_start(GvcApplet *applet);
gboolean gvc_applet_fill(GvcApplet *applet, MatePanelApplet *applet_widget);

G_END_DECLS

#endif /* __GVC_APPLET_H */
