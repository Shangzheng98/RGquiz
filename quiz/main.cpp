#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc.hpp"
#include "question_list.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>

using namespace std;
using namespace cv;

vector<Point> lst;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        lst.push_back(Point(x,y));
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_RBUTTONDOWN )
    {
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == EVENT_MBUTTONDOWN )
    {
        cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if ( event == EVENT_MOUSEMOVE )
    {
        cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

    }
}

/*void sequencialCout(string content){
    for(int i=0;i<content.length();i++){
        cout<<content[i];
        usleep(105000);
    }
}*/

bool ask(string str,int index){
    string q=str;
    cout<<q<<endl;
    Mat img;
    if(q[0]==50){
        if(q[1]==51){
            img=imread("img1.jpg");
            resize(img, img, Size(960,480));
            imshow("Demo",img);
        }
        if(q[1]==52){
            img=imread("img2.png");
            resize(img, img, Size(720,480));
            imshow("Demo",img);
        }
        if(q[1]==53){
            img=imread("img3.png");
            resize(img, img, Size(960,480));
            imshow("Demo",img);
        }
    }
    waitKey(10);
    string ans="";
    getline(cin,ans);

    for(int i=0;i<ans.length();i++){
        ans[i]=tolower(ans[i]);
    }
    stringstream ss( ans );
    vector<string> result;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, '|' );
        stringstream subss(substr);
        subss>>substr;
        result.push_back( substr );

    }
    int fin=0;
    for(int i=0;i<result.size();i++){
        fin<<=4;
        fin|=result[i][0];
    }
    return fin==index;
}

int main(int argc, char** argv){
    string welcomeinfo="Thank you for choosing RoboGrinder CV Department! And Congratulation! You have completed the first part of the test, which gives you 50 points as base. Then there are 25 questions in multiple choice, and they each worth 2 points. If you think multiple answers are good, enter and seperate them with | (like a bitwise or operator)sign. Good Luck!";
    cout<<welcomeinfo;
    cout<<endl<<endl<<endl;
    int score=0;
    //---------------the test starts-------------------
    for(int i=0;i<25;i++){
        bool right=ask(questions[i],a_q[i]);
        if(right){
            score+=2;
        }
    }

    if(score!=0){
        score+=50;
    }

    cout<<"Your score is: "<<score<<endl;
    cout<<"RoboGrinder Wins"<<endl;
    return 0;
}
