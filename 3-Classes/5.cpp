#include <iostream>
#include <fstream> 
#include <ctime>
#include <queue>

using namespace std;

class Logger{
    private:
        ofstream File;
        string fname;
        string getCurrentTime(){
            time_t timestamp;
            return "[" + to_string(time(&timestamp)) + "]";
        }
    public:
        Logger(string filename) : File(filename) {
            fname = filename;
        };
        ~Logger(){
            File.close();
        }
        void log(int level, string msg){
            switch (level){
                case 0:
                    File << getCurrentTime() << " DEBUG: " << msg << endl;
                    break;
                case 1:
                    File << getCurrentTime() << " INFO: " << msg << endl;
                    break;
                case 2:
                    File << getCurrentTime() << " LOG: " << msg << endl;
                    break;
                case 3:
                    File << getCurrentTime() << " WARN: " << msg << endl;
                    break;
                case 4:
                    File << getCurrentTime() << " ERR: " << msg << endl;
                    break;
                default:
                    File << getCurrentTime() << " UNKNWN: " << msg << endl;
                    break;
            }
        }
        void printLogs(string filename = "") const {
            if (filename.empty()) filename = fname;
            string temp;
            ifstream tempreader(filename);
            while(getline(tempreader, temp)){
                cout << temp << endl;
            }
        }
        void head(string filename = "", int cnt = 3) const {
            if (filename.empty()) {filename = fname;}
            string temp;
            ifstream tempreader(filename);
            int i = 0;

            while (getline(tempreader, temp)){
                cout << i << ": " << temp << endl;
                i++;
                if (i >= cnt) break;
            }
        }

        void tail(string filename = "", int cnt = 3) const {
            if (filename.empty()) {filename = fname;}
            queue<string> tempqueue;
            string temp;
            ifstream tempreader(filename);
            int linenumber = 0;
            while (getline(tempreader, temp)){
                tempqueue.push(temp);
                linenumber++;
                if (tempqueue.size() > cnt){
                    tempqueue.pop();
                }
            }
            int realsize = min(cnt, (int)tempqueue.size());
            int i = 0;
            while (!tempqueue.empty()){
                cout << linenumber-realsize+i << ": " << tempqueue.front() << endl;
                tempqueue.pop();
                i++;
            }
            
        }
};

int main() {
    Logger logger("a.txt");
    logger.log(0, "test1");
    logger.log(1, "test2");
    logger.log(2, "test3");
    logger.log(3, "test4");
    logger.log(3, "test5");
    logger.log(3, "test6");
    logger.log(3, "test7");
    logger.log(3, "test8");
    logger.log(4, "error waaaah");
    logger.log(123123, "unknown");
    logger.printLogs("a.txt");
    cout << "=====" << endl;
    logger.head();
    cout << "=====" << endl;
    logger.tail();
    cout << "==========" << endl;
    Logger logger2("b.txt");
    logger2.log(0, "test1");
    logger2.log(1, "test2");
    logger2.printLogs("b.txt");
    cout << "=====" << endl;
    logger2.head();
    cout << "=====" << endl;
    logger2.tail();
    return 0;
}