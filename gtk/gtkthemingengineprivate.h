/* GTK - The GIMP Toolkit
 * Copyright (C) 2010 Carlos Garnacho <carlosg@gnome.org>
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
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_THEMING_ENGINE_PRIVATE_H__
#define __GTK_THEMING_ENGINE_PRIVATE_H__

#include <gdk/gdk.h>
#include "gtk/gtkthemingengine.h"
#include "gtk/gtkcssvalueprivate.h"

G_BEGIN_DECLS

void _gtk_theming_engine_paint_spinner (cairo_t       *cr,
                                        gdouble        radius,
                                        gdouble        progress,
                                        const GdkRGBA *color);

GtkCssValue  *_gtk_theming_engine_peek_property (GtkThemingEngine *engine,
                                                 guint             property_id);
void          _gtk_theming_engine_set_context   (GtkThemingEngine *engine,
                                                 GtkStyleContext  *context);
GtkStyleContext *_gtk_theming_engine_get_context   (GtkThemingEngine *engine);

G_END_DECLS

#endif /* __GTK_THEMING_ENGINE_PRIVATE_H__ */
