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
#include "ChartsApp.h"
#include "src/avitab/apps/components/FileSelect.h"
#include "src/avitab/apps/components/PDFViewer.h"
#include "src/platform/Platform.h"

namespace avitab {

ChartsApp::ChartsApp(FuncsPtr appFuncs):
    App(appFuncs)
{
    currentPath = api().getDataPath() + "charts/";
    // showFileSelect();
    resetLayout();
}

void ChartsApp::resetLayout() {
    tabs = std::make_shared<TabGroup>(getUIContainer());
    tabs->centerInParent();
    createBrowseTab();
}

void ChartsApp::createBrowseTab() {
    browsePage = tabs->addTab(tabs, "Files");
    browseWindow = std::make_shared<Window>(browsePage, "Files");
    browseWindow->setDimensions(browsePage->getContentWidth(), browsePage->getHeight());
    browseWindow->centerInParent();

    browseWindow->setOnClose([this] { exit(); });
    browseWindow->addSymbol(Widget::Symbol::DOWN, [this] () { onDown(); });
    browseWindow->addSymbol(Widget::Symbol::UP, [this] () { onUp(); });
    browseList = std::make_shared<List>(browseWindow);
    browseList->setDimensions(browseWindow->getContentWidth(), browseWindow->getContentHeight());
    browseList->setCallback([this] (int data) {
        api().executeLater([this, data] {
            onSelect(data);
        });
    });
}

void ChartsApp::onDown() {

}

void ChartsApp::onUp() {

}

void ChartsApp::onSelect(int data) {

}








// void ChartsApp::show() {
//     if (childApp) {
//         childApp->show();
//     }
// }

// void ChartsApp::showFileSelect() {
//     auto fileSelect = startSubApp<FileSelect>();
//     fileSelect->setOnExit([this] () { exit(); });
//     fileSelect->setSelectCallback([this] (const std::vector<platform::DirEntry> &entries, size_t i) {
//         onSelect(entries, i);
//     });
//     fileSelect->setFilterRegex("\\.(pdf|png|jpg|jpeg|bmp)$");
//     fileSelect->showDirectory(currentPath);
//     childApp = std::move(fileSelect);
// }

// void ChartsApp::onSelect(const std::vector<platform::DirEntry> &entries, size_t chosenIndex) {
//     currentPath = std::dynamic_pointer_cast<FileSelect>(childApp)->getCurrentPath();

//     auto pdfApp = startSubApp<PDFViewer>();
//     pdfApp->showDirectory(currentPath, entries, chosenIndex);
//     pdfApp->setOnExit([this] () {
//         api().executeLater([this] {
//             onSelectionClosed();
//         });
//     });

//     childApp = std::move(pdfApp);
//     childApp->show();
// }

// void ChartsApp::onMouseWheel(int dir, int x, int y) {
//     if (childApp) {
//         childApp->onMouseWheel(dir, x, y);
//     }
// }

// void ChartsApp::onSelectionClosed() {
//     showFileSelect();
//     childApp->show();
// }

} /* namespace avitab */
