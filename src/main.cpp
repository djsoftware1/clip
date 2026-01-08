// clip
// 8 Jan 2026 - Created by David Joffe

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

static int run_command(const std::string& cmd) {
    return std::system(cmd.c_str());
}

static int copy_stdin() {
#if defined(_WIN32)
    return run_command("clip");
#elif defined(__APPLE__)
    return run_command("pbcopy");
#else
    // Linux / Unix
    if (run_command("which wl-copy > /dev/null 2>&1") == 0)
        return run_command("wl-copy");
    if (run_command("which xclip > /dev/null 2>&1") == 0)
        return run_command("xclip -selection clipboard");
    if (run_command("which xsel > /dev/null 2>&1") == 0)
        return run_command("xsel --clipboard --input");

    std::cerr << "clip: no clipboard backend found (wl-copy, xclip, xsel)\n";
    return 1;
#endif
}

static int paste_stdout() {
#if defined(_WIN32)
    return run_command("powershell -command Get-Clipboard");
#elif defined(__APPLE__)
    return run_command("pbpaste");
#else
    if (run_command("which wl-paste > /dev/null 2>&1") == 0)
        return run_command("wl-paste");
    if (run_command("which xclip > /dev/null 2>&1") == 0)
        return run_command("xclip -selection clipboard -o");
    if (run_command("which xsel > /dev/null 2>&1") == 0)
        return run_command("xsel --clipboard --output");

    std::cerr << "clip: no clipboard backend found (wl-paste, xclip, xsel)\n";
    return 1;
#endif
}

int main(int argc, char** argv) {
    if (argc == 1) {
        // Default: stdin → clipboard
        return copy_stdin();
    }

    if (argc == 2) {
        if (std::strcmp(argv[1], "-p") == 0 ||
            std::strcmp(argv[1], "--paste") == 0) {
            return paste_stdout();
        }
    }

    std::cerr << "usage:\n"
              << "  clip            copy stdin to clipboard\n"
              << "  clip -p         paste clipboard to stdout\n";
    return 1;
}
