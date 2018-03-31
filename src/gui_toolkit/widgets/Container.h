/*
 *   AviTab - Aviator's Virtual Tablet
 *   Copyright (C) 2018 Folke Will <folko@solhost.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Affero General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Affero General Public License for more details.
 *
 *   You should have received a copy of the GNU Affero General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef SRC_GUI_TOOLKIT_WIDGETS_CONTAINER_H_
#define SRC_GUI_TOOLKIT_WIDGETS_CONTAINER_H_

#include "Widget.h"

namespace avitab {

class Container: public Widget {
public:
    Container(WidgetPtr parent);
    void setLayoutPretty();
    void setLayoutRightColumns();
};

} /* namespace avitab */

#endif /* SRC_GUI_TOOLKIT_WIDGETS_CONTAINER_H_ */
