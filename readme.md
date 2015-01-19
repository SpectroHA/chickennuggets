Chickennuggets Version 2.0.0.0 Full Release

================================

http://www.scsycoin.com

Copyright (c) 2014 Chickennuggets Developers

Build Instructions for QT5 Linux Wallet
======================================
Create a folder named Chickennuggets in /home/ and unpack the contents of ~/Chickennuggets-master to that folder.

Install dependencies via Terminal:

$ sudo apt-get install make libqt5webkit5-dev libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler build-essential libboost-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev libevent-dev libcurl4-openssl-dev git libpng-dev qrencode libqrencode-dev

//In terminal navigate to the Chickennuggets folder.

$ cd /home/Chickennuggets

//Create the src/obj folder

$ mkdir src/obj

//Enter in to the terminal:

$ qmake -qt=qt5 "USE_QRCODE=1" "USE_UPNP=-"

//Then:

$ make

This will compile and build the QT Wallet which takes a little while, please be patient.

When finished you will have a file called Chickennuggets-QT - Simply Double Click

//end of guide


Build Instructions for Terminal Based Linux Wallet
===================================================
//Create a folder named Chickennuggets in /home/ and unpack the contents of ~/Chickennuggets-master to that folder.

//Install dependencies via Terminal:

$ sudo apt-get install build-essential libboost-all-dev libcurl4-openssl-dev libdb5.1-dev libdb5.1++-dev qt-sdk make 

//In terminal navigate to the Chickennuggets folder.

$ cd /home/Chickennuggets/src/

//Create the obj folder

$ mkdir obj

//Enter into the terminal:

$ make -f makefile.unix "USE_UPNP=-"

//This will produce a file named chickennuggetsd which is the command line instance of Chickennuggets-qt

//Now type:

$ strip chickennuggetsd

//When finished you will have a file called chickennuggetsd

//To run Chickennuggets

$ ./chickennuggetsd & 

//It will complain about having no chickennuggets.conf file, we'll edit the one provided and move it into place

$ cd ..
$ nano chickennuggets.conf

//Edit the Username and Password fields to anything you choose (but remember them) then save the file

$ mv chickennuggets.conf /home/Chickennuggets/src/
$ cd src/
$ ./chickennuggetsd &

//The server will start. Here are a few commands, google for more.

$ ./chickennuggetsd getinfo
$ ./chickennuggetsd getmininginfo
$ ./chickennuggetsd getnewaddresss

//end of guide


License
-------

Chickennuggets is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Chickennuggets
development team members simply pulls it.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/Chickennuggets-project/Chickennuggets) are created
regularly to indicate new official, stable release versions of Chickennuggets.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake Chickennuggets_QT_TEST=1 -o Makefile.test Chickennuggets-qt.pro
    make -f Makefile.test
    ./Chickennuggets-qt_test
    
//End of ReadMe
