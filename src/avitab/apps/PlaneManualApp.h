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
#ifndef SRC_AVITAB_APPS_PLANEMANUALAPP_H_
#define SRC_AVITAB_APPS_PLANEMANUALAPP_H_

#include "App.h"
#include "src/gui_toolkit/widgets/MessageBox.h"

namespace avitab {

class PlaneManualApp: public App {
public:
    PlaneManualApp(FuncsPtr appFuncs);
    void show() override;
private:
    std::shared_ptr<MessageBox> errorMsg;
    std::shared_ptr<App> childApp;
    std::string currentPath;

    void showFileSelect();
    void onSelect(const std::string &nameUtf8);
};

} /* namespace avitab */

#endif /* SRC_AVITAB_APPS_PLANEMANUALAPP_H_ */