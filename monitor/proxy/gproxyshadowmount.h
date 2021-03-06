/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
/* gvfs - extensions for gio
 *
 * Copyright (C) 2006-2008 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Author: David Zeuthen <davidz@redhat.com>
 */

#ifndef __G_PROXY_SHADOW_MOUNT_H__
#define __G_PROXY_SHADOW_MOUNT_H__

#include <glib-object.h>
#include <gio/gio.h>

#include "gproxyvolumemonitor.h"

G_BEGIN_DECLS

#define G_TYPE_PROXY_SHADOW_MOUNT        (g_proxy_shadow_mount_get_type ())
#define G_PROXY_SHADOW_MOUNT(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_PROXY_SHADOW_MOUNT, GProxyShadowMount))
#define G_PROXY_SHADOW_MOUNT_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_PROXY_SHADOW_MOUNT, GProxyShadowMountClass))
#define G_IS_PROXY_SHADOW_MOUNT(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_PROXY_SHADOW_MOUNT))
#define G_IS_PROXY_SHADOW_MOUNT_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_PROXY_SHADOW_MOUNT))

typedef struct _GProxyShadowMountClass GProxyShadowMountClass;

struct _GProxyShadowMountClass {
   GObjectClass parent_class;
};

GType              g_proxy_shadow_mount_get_type            (void) G_GNUC_CONST;
void               g_proxy_shadow_mount_register            (GIOModule           *module);
GProxyShadowMount *g_proxy_shadow_mount_new                 (GProxyVolumeMonitor *volume_monitor,
                                                             GProxyVolume        *volume,
                                                             GMount              *real_mount);
GMount            *g_proxy_shadow_mount_get_real_mount      (GProxyShadowMount   *mount);
GFile             *g_proxy_shadow_mount_get_activation_root (GProxyShadowMount   *mount);
gboolean           g_proxy_shadow_mount_has_mount_path      (GProxyShadowMount   *mount,
                                                             const char          *mount_path);
void               g_proxy_shadow_mount_remove              (GProxyShadowMount   *mount);

G_END_DECLS

#endif /* __G_PROXY_SHADOW_MOUNT_H__ */
