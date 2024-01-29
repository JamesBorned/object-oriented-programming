//#include <winuser.h>
#include "Workflow.h"
#include "Keyboard.h"

void Workflow() {
        Keyboard keyboard;
        std::vector<std::string> keys;

        keyboard.setKeys(keys);
//        char buf[128] = {0};
//        for (long n = 0; n < 256; ++n){
//            ::GetKeyNameTextA(n << 16, buf, 128);
//            std::cout << buf << std::endl;
//        }
        //Key key;
        /*key.Command = "";

        keyboard.Addkey(key);

        keyboard.Presskey("a");
        std::this_thread::sleep_for(std::chrono::milliseconds{500});
        keyboard.PressKeys("b");
        std::this_thread::sleep_for(std::chrono::milliseconds{500});
        keyboard.PressKeys("Alt+b");
        std::this_thread::sleep_for(std::chrono::milliseconds{500});
        keyboard.Undo();
        std::this_thread::sleep_for(std::chrono::milliseconds{500});
        //keyboard.

        key.Command = "";

        delete keyboard;*/
}