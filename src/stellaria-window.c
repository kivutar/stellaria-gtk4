/* MIT License
 *
 * Copyright (c) 2023 Jean-André Santoni
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#include <webkit/webkit.h>

#include "config.h"

#include "stellaria-window.h"

struct _StellariaWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
	GtkHeaderBar        *header_bar;
        GtkBox              *main_box;
};

G_DEFINE_FINAL_TYPE (StellariaWindow, stellaria_window, ADW_TYPE_APPLICATION_WINDOW)

static void
stellaria_window_class_init (StellariaWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/me/kivutar/Stellaria/stellaria-window.ui");
        gtk_widget_class_bind_template_child (widget_class, StellariaWindow, main_box);
	gtk_widget_class_bind_template_child (widget_class, StellariaWindow, header_bar);
}

static void
stellaria_window_init (StellariaWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));

        WebKitWebView *webView = WEBKIT_WEB_VIEW (webkit_web_view_new());

        const char *url = "http://astro.kivutar.me/transform?xml=http%3A%2F%2Fgoastrows.herokuapp.com/%2Fchartinfo%3Flat%3D43.13517%26lon%3D5.848%26year%3D1984%26month%3D6%26day%3D8%26time%3D13.25%26hsys%3DE%26display%3D0%2C1%2C2%2C3%2C4%2C5%2C6%2C7%2C8%2C9%2C10%2C12%2C23&xsl=wheel.xsl";
        webkit_web_view_load_uri(webView, url);

        gtk_box_append (self->main_box, GTK_WIDGET (webView));
        gtk_widget_set_vexpand(GTK_WIDGET (webView), true);
}
