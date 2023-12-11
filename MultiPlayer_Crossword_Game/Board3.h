#include <iostream>
#include <iomanip>
using namespace std;

class board3
{
private:
    char ans[16][16];

public:
    struct question
    {
        int Q_No;
        int points;
        string answer;
        pair<int,int> start;
        pair<int,int> end;
        string hint1;
        string hint2;
        bool across_or_down;       //if 1 across else if 0 down.
    } Q[29];
    int qm[4][29];
    int totalQuestions=29;

    board3()
    {
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                ans[i][j]=' ';
            }
        }
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<29;j++)
                qm[i][j]=-1;
            
        }
        
        //Question Numbers
        for(int i=0;i<25;i++)
        {
            Q[i].Q_No=i+1;
        }

        //points
        Q[0].points=30;
        Q[1].points=30;
        Q[2].points=30;
        Q[3].points=30;
        Q[4].points=30;
        Q[5].points=30;
        Q[6].points=30;
        Q[7].points=30;
        Q[8].points=30;
        Q[9].points=30;
        Q[10].points=40;
        Q[11].points=40;
        Q[12].points=40;
        Q[13].points=40;
        Q[14].points=40;
        Q[15].points=40;
        Q[16].points=40;
        Q[17].points=40;
        Q[18].points=40;
        Q[19].points=40;
        Q[20].points=50;
        Q[21].points=50;
        Q[22].points=50;
        Q[23].points=50;
        Q[24].points=50;
        Q[25].points=50;
        Q[26].points=50;
        Q[27].points=50;
        Q[28].points=50;

        //across-down
        Q[0].across_or_down=0;
        Q[1].across_or_down=0;
        Q[2].across_or_down=0;
        Q[3].across_or_down=0;
        Q[4].across_or_down=0;
        Q[5].across_or_down=1;
        Q[6].across_or_down=0;
        Q[7].across_or_down=1;
        Q[8].across_or_down=1;
        Q[9].across_or_down=0;
        Q[10].across_or_down=1;
        Q[11].across_or_down=1;
        Q[12].across_or_down=0;
        Q[13].across_or_down=0;
        Q[14].across_or_down=0;
        Q[15].across_or_down=1;
        Q[16].across_or_down=0;
        Q[17].across_or_down=1;
        Q[18].across_or_down=0;
        Q[19].across_or_down=1;
        Q[20].across_or_down=1;
        Q[21].across_or_down=1;
        Q[22].across_or_down=1;
        Q[23].across_or_down=0;
        Q[24].across_or_down=1;
        Q[25].across_or_down=0;
        Q[26].across_or_down=1;
        Q[27].across_or_down=1;
        Q[28].across_or_down=1;

        //Answers
        Q[0].answer="DOPPLER";
        Q[1].answer="ALLOY";
        Q[2].answer="APPLE";
        Q[3].answer="DAVY";
        Q[4].answer="CELSIUS";
        Q[5].answer="AEROGEL";
        Q[6].answer="EVOLUTION";
        Q[7].answer="APE";
        Q[8].answer="ZOOLOGY";
        Q[9].answer="GAS";
        Q[10].answer="TUBE";
        Q[11].answer="REPORT";
        Q[12].answer="EDISON";
        Q[13].answer="ONCOLOGY";
        Q[14].answer="THEORY";
        Q[15].answer="NASA";
        Q[16].answer="ANALYSIS";
        Q[17].answer="PIG";
        Q[18].answer="NEWTON";
        Q[19].answer="UNITS";
        Q[20].answer="OZONE";
        Q[21].answer="LAB";
        Q[22].answer="NEON";
        Q[23].answer="EXAM";
        Q[24].answer="TESLA";
        Q[25].answer="ADA";
        Q[26].answer="GRAVITY";
        Q[27].answer="VENUS";
        Q[28].answer="ALAN";

        //Answer Co-ordinates
        Q[0].start.first=1;
        Q[0].start.second=4;
        Q[0].end.first=7;
        Q[0].end.second=4;

        Q[1].start.first=1;
        Q[1].start.second=7;
        Q[1].end.first=5;
        Q[1].end.second=7;

        Q[2].start.first=1;
        Q[2].start.second=9;
        Q[2].end.first=5;
        Q[2].end.second=9;

        Q[3].start.first=1;
        Q[3].start.second=12;
        Q[3].end.first=4;
        Q[3].end.second=12;

        Q[4].start.first=1;
        Q[4].start.second=14;
        Q[4].end.first=7;
        Q[4].end.second=14;

        Q[5].start.first=2;
        Q[5].start.second=1;
        Q[5].end.first=2;
        Q[5].end.second=7;

        Q[6].start.first=2;
        Q[6].start.second=2;
        Q[6].end.first=10;
        Q[6].end.second=2;

        Q[7].start.first=2;
        Q[7].start.second=12;
        Q[7].end.first=2;
        Q[7].end.second=14;

        Q[8].start.first=4;
        Q[8].start.second=6;
        Q[8].end.first=4;
        Q[8].end.second=12;

        Q[9].start.first=4;
        Q[9].start.second=11;
        Q[9].end.first=6;
        Q[9].end.second=11;

        Q[10].start.first=6;
        Q[10].start.second=1;
        Q[10].end.first=6;
        Q[10].end.second=4;

        Q[11].start.first=7;
        Q[11].start.second=4;
        Q[11].end.first=7;
        Q[11].end.second=9;

        Q[12].start.first=7;
        Q[12].start.second=5;
        Q[12].end.first=12;
        Q[12].end.second=5;

        Q[13].start.first=7;
        Q[13].start.second=7;
        Q[13].end.first=14;
        Q[13].end.second=7;

        Q[14].start.first=7;
        Q[14].start.second=9;
        Q[14].end.first=12;
        Q[14].end.second=9;

        Q[15].start.first=7;
        Q[15].start.second=12;
        Q[15].end.first=7;
        Q[15].end.second=15;

        Q[16].start.first=7;
        Q[16].start.second=13;
        Q[16].end.first=14;
        Q[16].end.second=13;

        Q[17].start.first=8;
        Q[17].start.second=1;
        Q[17].end.first=8;
        Q[17].end.second=3;

        Q[18].start.first=9;
        Q[18].start.second=11;
        Q[18].end.first=14;
        Q[18].end.second=11;

        Q[19].start.first=10;
        Q[19].start.second=1;
        Q[19].end.first=10;
        Q[19].end.second=5;

        Q[20].start.first=10;
        Q[20].start.second=7;
        Q[20].end.first=10;
        Q[20].end.second=11;

        Q[21].start.first=10;
        Q[21].start.second=13;
        Q[21].end.first=10;
        Q[21].end.second=15;

        Q[22].start.first=12;
        Q[22].start.second=2;
        Q[22].end.first=12;
        Q[22].end.second=5;

        Q[23].start.first=12;
        Q[23].start.second=3;
        Q[23].end.first=15;
        Q[23].end.second=3;

        Q[24].start.first=12;
        Q[24].start.second=11;
        Q[24].end.first=12;
        Q[24].end.second=15;

        Q[25].start.first=12;
        Q[25].start.second=15;
        Q[25].end.first=14;
        Q[25].end.second=15;

        Q[26].start.first=14;
        Q[26].start.second=1;
        Q[26].end.first=14;
        Q[26].end.second=7;

        Q[27].start.first=14;
        Q[27].start.second=9;
        Q[27].end.first=14;
        Q[27].end.second=13;

        //hint1
        Q[0].hint1="a shift in frequency ";
        Q[1].hint1="mixture of metals and non-metals";
        Q[2].hint1="a hard, round fruit with a smooth green, red or yellow skin";
        Q[3].hint1="beloved; son of David";
        Q[4].hint1="the name of a scale for measuring temperatures, in which water freezes at 0° and boils at 100°";
        Q[5].hint1="a suspension of fine solid or liquid particles in gas";
        Q[6].hint1="the development of plants, animals, etc. over many thousands of years from simple early forms to more advanced ones";
        Q[7].hint1="a type of animal like a large monkey with no tail or only a very short tail";
        Q[8].hint1="the scientific study of animals";
        Q[9].hint1="a substance like air that is not a solid or a liquid";
        Q[10].hint1="a long empty pipe";
        Q[11].hint1="to give people information about what you have seen, heard, done, etc.";
        Q[12].hint1=" scientist who invented bulb";
        Q[13].hint1="the study and treatment of tumours";
        Q[14].hint1="an idea or set of ideas that tries to explain something";
        Q[15].hint1="agency that is responsible for science and technology related to air and space";
        Q[16].hint1="the careful examination of the different parts or details of something";
        Q[17].hint1="a fat pinkish animal with short legs and a short tail";
        Q[18].hint1="Newton- a unit of force";
        Q[19].hint1="a fixed amount or number used as a standard of measurement";
        Q[20].hint1="a poisonous gas which is a form of oxygen";
        Q[21].hint1="building where science experiments are done";
        Q[22].hint1="a type of gas that does not react with anything";
        Q[23].hint1="a written, spoken or practical test of what you know or can do";
        Q[24].hint1="the SI derived unit of magnetic flux density";
        Q[25].hint1="a high-level computer programming language used chiefly in real-time computerized control systems,";
        Q[26].hint1="the natural force that makes things fall to the ground when you drop them";
        Q[27].hint1="the planet that is second in order from the sun and nearest to the earth";
        Q[28].hint1="male name,precious,handsome";

    }

    void queHint2(int questionNo)
    {
        int n=questionNo;
        int x;
        // cout<<"\nWhich letter you want to reveal: ";
        // cin>>x;
        int flag=0;
        while(flag==0)
        {
            cout<<"\nWhich letter you want to reveal: ";
            cin>>x;
            if(Q[n].across_or_down==1)
            {
                int i=Q[n].start.first;
                int j=Q[n].start.second+x-1;
                if(ans[i][j]==' ')
                {
                    cout<<Q[n].answer[x-1];
                    flag=1;
                }
                else{
                    cout<<"\nThe letter is already revealed! Please check the board!";
                    //flag=1;
                }
            }
            else{
                int i=Q[n].start.first+x-1;
                int j=Q[n].start.second;
                if(ans[i][j]==' ')
                {
                    cout<<Q[n].answer[x-1];
                    flag=1;
                }
                else{
                    cout<<"\nThe letter is already revealed! Please check the board!";
                    //flag=1;
                }
            }
        }
    }

    void update_board(int questionNo)
    {
        int x=questionNo;
        int i,j;
        int k=0;
        if(Q[x].across_or_down==1)
        {
            i=Q[x].start.first;
            for(j=Q[x].start.second;j<=Q[x].end.second;j++)
            {
                ans[i][j]=Q[x].answer[k];
                k++;
            }
            k=0;
        }
        else{
            j=Q[x].start.second;
            for(i=Q[x].start.first;i<=Q[x].end.first;i++)
            {
                ans[i][j]=Q[x].answer[k];
                k++;
            }
            k=0;
        }
    }

    void display()
    {
        cout<<"\t\t _\x1b[4m \x1b[0m_\t     _\x1b[4m \x1b[0m_     _\x1b[4m \x1b[0m_";
        cout<<"\t _\x1b[4m \x1b[0m_     _\x1b[4m \x1b[0m_"<<endl;
        int c=0;
        //0th row
        cout<<"\t _\x1b[4m \x1b[0m_    |";
        for(int i=4;i<15;i++)
        {
            if(i==4)
            {
                cout<<"_\x1b[4m1\x1b[0m_|";
            }
            else if(i==5)
            {
                cout<<"    ";
            }
            else if(i==6 || i==8 || i==10)
            {
                if(i==10)
                {
                    cout<<"_\x1b[4m \x1b[0m_";
                }
                else{
                    cout<<"_\x1b[4m \x1b[0m_|";
                }
            }
            else if(i==7)
            {
                cout<<"_\x1b[4m2\x1b[0m_|";
            }
            else if(i==9)
            {
                cout<<"_\x1b[4m3\x1b[0m_|";
            }
            else if(i==11 || i==13)
            {
                cout<<"   ";
            }
            else if(i==12)
            {
                cout<<" |_\x1b[4m4\x1b[0m_|";
            }
            else if(i==14)
            {
                cout<<"|_\x1b[4m5\x1b[0m_|";
            }
        }
        cout<<endl;

        //1st row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<15;i++)
        {
            if(i==2)
            {
                cout<<"_\x1b[4m7\x1b[0m_|";
            }
            else if(i==6)
            {
                cout<<"\x1b[4m29\x1b[0m_|";
            }
            else if(i==3 || i==5 || i==11 || i==13)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[1][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //2th row
        c=0;
        for(int i=0;i<15;i++)
        {
            if(i==0)
            {
                cout<<"|_\x1b[4m6\x1b[0m_|";
            }
            else if(i==8 || i==10)
            {
                cout<<"   |";
            }
            else if(i==11)
            {
                cout<<"_\x1b[4m8\x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[2][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //3rd row
        c=2;
        cout<<"\t|";
        for(int i=2;i<15;i++)
        {
            if(i==3 || i==13)
            {
                cout<<"   |";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==6 || i==8 || i==10)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==11)
            {
                cout<<"_\x1b[4m10\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[3][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //4th row
        c=2;
        cout<<"\t|";
        for(int i=2;i<15;i++)
        {
            if(i==3 || i==13)
            {
                cout<<"   |";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m9\x1b[0m_|"; 
            }
            else{
                cout<<"_\x1b[4m"<<ans[4][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //5th row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<15;i++)
        {
            if(i==3 || i==13)
            {
                cout<<"_\x1b[4m \x1b[0m_|"; 
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m \x1b[0m_ "; 
            }
            else if(i==6 || i==8 || i==10 || i==12)
            {
                if(i==12)
                {
                    cout<<"    ";
                }
                else{
                    cout<<"   |";
                }
            }
            else{
                cout<<"_\x1b[4m"<<ans[5][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //6th row
        c=0;
        for(int i=0;i<15;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m11\x1b[0m_|";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m13\x1b[0m|";
            }
            else if(i==7)
            {
                cout<<"_\x1b[4m14\x1b[0m|";
            }
            else if(i==9)
            {
                cout<<"_\x1b[4m15\x1b[0m|";
            }
            else if(i==13)
            {
                cout<<"_\x1b[4m17\x1b[0m|";
            }
            else if(i==6 || i==8 || i==12)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==10)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans[6][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<"_\x1b[4m \x1b[0m_"<<endl;

        //7th row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<16;i++)  
        {
            if(i==3)
            {
                cout<<"_\x1b[4m12\x1b[0m|";
            }
            else if(i==11)
            {
                cout<<"_\x1b[4m16\x1b[0m|";
            }
            else if(i==10)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans[7][c]<<"\x1b[0m_|";
            }
            c++;
        }  
        cout<<endl;

        //8th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m18\x1b[0m_|"; 
            }
            else if(i==11)
            {
                cout<<"_\x1b[4m19\x1b[0m|"; 
            }
            else if(i==4 || i==6 || i==8 || i==10 || i==12)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans[8][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //9th row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<14;i++)
        {
            if(i==3)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==4 || i==6 || i==8 || i==10 || i==12)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[9][c]<<"\x1b[0m_|";
            }
            c++;
        } 
        cout<<"_\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_"<<endl;

        //10th row
        c=0;
        for(int i=0;i<16;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m20\x1b[0m_|";
            }
            else if(i==6)
            {
                cout<<"_\x1b[4m21\x1b[0m|";
            }
            else if(i==12)
            {
                cout<<"_\x1b[4m22\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[10][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //11th row
        c=3;
        cout<<"     _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=3;i<16;i++)
        {
            if(i==3)
            {
                cout<<"\x1b[4m24\x1b[0m_|";
            }
            else if(i==4 || i==10 || i==12 || i==14)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==6 || i==8)
            {
                cout<<"   |";
            }
            else if(i==15)
            {
                cout<<"_\x1b[4m26\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[11][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //12th row
        c=1;
        cout<<"    |";
        for(int i=1;i<16;i++)
        {
            if(i==1)
            {
                cout<<"\x1b[4m23\x1b[0m_|";
            }
            else if(i==6 || i==8)
            {
                cout<<"   |";
            }
            else if(i==10)
            {
                cout<<"_\x1b[4m25\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans[12][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //13th row
        c=3;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=3;i<16;i++)
        {
            if(i==4 || i==5 || i==8 || i==9)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==6 || i==10 || i==12)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==14)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans[13][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //14th row
        c=0;
        for(int i=0;i<16;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m27\x1b[0m_|";
            }
            else if(i==8)
            {
                cout<<"_\x1b[4m28\x1b[0m|";
            }
            else if(i==14)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans[14][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //15th row
        cout<<"\t    |_\x1b[4m"<<ans[15][3]<<"\x1b[0m_|";
        cout<<endl;
        cout<<"EASY"<<endl;
        cout<<endl;
        cout<<"1.Device for transmiting copies"<<endl;
        cout<<"2.Microsofts first gaming console"<<endl;
        cout<<"4.Encoded series of transactions used in cryptocurrency"<<endl;
        //cout<<"5.Elon musk's rocket launching corporation"<<endl;
        // cout<<"6.Downloadable program on a mobile device"<<endl;
        // cout<<"13.Computer cooler"<<endl;
        // cout<<"16.Tool used to drive nails into wood"<<endl;
        // cout<<"17.Electricity producing machine"<<endl;
        // cout<<"18.Local area network that uses high frequency radio signals to transmit a"<<endl;
        // cout<<"20.Commonly used computerized cash machine"<<endl;
        // cout<<"22.System of numerical notation that has 2 rather than 10 as a base"<<endl;
        
        cout<<endl;
        cout<<"MEDIUM"<<endl<<endl;        
        cout<<"3.Makes music even louder"<<endl;
        cout<<"4.Sending out high frequency waves to detect objects"<<endl;
        cout<<"7.This is the main electronic circuit board in your computer"<<endl;
        // cout<<"11.Aparatus that measures air pressure"<<endl;
        // cout<<"21.Cisco ______, company sells networking equipment"<<endl;
        // cout<<"23.Device in a car used to start engine"<<endl;
        
        cout<<endl;
        cout<<"HARD"<<endl<<endl;
        cout<<"8.Wireless tech for short distance data exchange"<<endl;
        cout<<"10.Developed a code for the telegraph"<<endl;
        cout<<"11._____ line, Henry ford's production technique"<<endl;
        // cout<<"14.Computer technology corporatin founded by Lary ellison"<<endl;        
        // cout<<"15.Machine tool for shaping metal or wood"<<endl;
        // cout<<"19.Organism obtained through genetic manipulation"<<endl;
        cout<<endl;
    }
};

// int main()
// {
//     char ans[16][16];
//     for(int i=0;i<16;i++)
//     {
//         for(int j=0;j<16;j++)
//         {
//             ans[i][j]=' ';
//         }
//     }

//     /*char x='a';
//     for(int i=0;i<16;i++)
//     {
//         for(int j=0;j<16;j++)
//         {
//             ans[i][j]=x;
//             x++;
//         }
//         x='a';
//     }*/
// }