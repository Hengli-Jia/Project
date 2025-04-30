#ifndef __CONSOLE_INPUT_H__
#define __CONSOLE_INPUT_H__

#include <string>
#include <fstream>

using namespace std;

enum CommandKey : char {
  noKey = 0, // we rely on this being zero, i.e. "false"

  tabKey = 0x09,
  enterKey = 0x0A,
  escapeKey = 0x1B,
  deleteKey = 0x7F,

  // Use high-bit values for special keys.
  unknownKey = char(0x80),
  arrowUpKey,
  arrowDownKey,
  arrowRightKey,
  arrowLeftKey,
  arrowUpLeftKey,
  arrowUpRightKey,
  arrowDownLeftKey,
  arrowDownRightKey,
  pageUpKey,
  pageDownKey,
  deleteForwardKey,
  commandKeyCount
};

/******************************************************************************/
/******************************************************************************/

class ConsoleInput {
public:
    ConsoleInput(string filename = "./recordedkeys.txt") : _filename(filename) {}
    virtual ~ConsoleInput() {};
    virtual char nextCommandKey(unsigned timeout) = 0;

protected:
    string _filename;
};

/******************************************************************************/
/******************************************************************************/

class UserConsoleInput : public ConsoleInput {
public:
    UserConsoleInput() {
        configureKeystrokeFile();
    }

    UserConsoleInput(string filename) : ConsoleInput(filename) {
        configureKeystrokeFile();
    }

    ~UserConsoleInput() override {
        _file.close();
    }
    
    // timeout specifies how long (in tenths of seconds) to wait for user input.
    // return zero if the timeout expires.
    // timeout == 0 waits indefintiely.
    virtual char nextCommandKey(unsigned timeout) override;

private:
    ofstream _file;

    void configureKeystrokeFile();
    char escapedCommandKey(char c);
};

/******************************************************************************/
/******************************************************************************/

class RecordedConsoleInput : public ConsoleInput {
public:
    RecordedConsoleInput() {
        configureKeystrokeFile();
    }

    RecordedConsoleInput(string filename) : ConsoleInput(filename) {
        configureKeystrokeFile();
    }

    ~RecordedConsoleInput() {
        _file.close();
    }

    // timeout specifies how long (in tenths of seconds) to wait before returning
    // timeout == 0 means use a reasonable default (0.5sec)
    char nextCommandKey(unsigned timeout) override;

private: 
    ifstream _file;

    void configureKeystrokeFile();
};

#endif