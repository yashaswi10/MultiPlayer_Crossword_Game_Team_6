#include <iostream>
#include <iomanip>
using namespace std;

class board2
{
private:
    char ans2[14][14];

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
    }Q[25];

    int qm[4][25];
    int totalQuestions=25;
    board2()
    {
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<14;j++)
            {
                ans2[i][j]=' ';
            }
        }
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<25;j++)
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
        Q[9].points=40;
        Q[10].points=40;
        Q[11].points=40;
        Q[12].points=40;
        Q[13].points=40;
        Q[14].points=40;
        Q[15].points=40;
        Q[16].points=40;
        Q[17].points=50;
        Q[18].points=50;
        Q[19].points=50;
        Q[20].points=50;
        Q[21].points=50;
        Q[22].points=50;
        Q[23].points=50;
        Q[24].points=50;

        //across-down
        Q[0].across_or_down=0;
        Q[1].across_or_down=0;
        Q[2].across_or_down=0;
        Q[3].across_or_down=0;
        Q[4].across_or_down=0;
        Q[5].across_or_down=0;
        Q[6].across_or_down=1;
        Q[7].across_or_down=1;
        Q[8].across_or_down=1;
        Q[9].across_or_down=1;
        Q[10].across_or_down=1;
        Q[11].across_or_down=0;
        Q[12].across_or_down=1;
        Q[13].across_or_down=1;
        Q[14].across_or_down=1;
        Q[15].across_or_down=0;
        Q[16].across_or_down=0;
        Q[17].across_or_down=0;
        Q[18].across_or_down=0;
        Q[19].across_or_down=0;
        Q[20].across_or_down=1;
        Q[21].across_or_down=1;
        Q[22].across_or_down=1;
        Q[23].across_or_down=1;
        Q[24].across_or_down=1;

        //Answers
        Q[0].answer="SUMMIT";
        Q[1].answer="DANGER";
        Q[2].answer="NICHE";
        Q[3].answer="EMBRACE";
        Q[4].answer="STALLION";
        Q[5].answer="TRACKS";
        Q[6].answer="IMMATURE";
        Q[7].answer="MAN";
        Q[8].answer="GATHER";
        Q[9].answer="LUCK";
        Q[10].answer="TORSO";
        Q[11].answer="SIDESTEP";
        Q[12].answer="ECLIPSE";
        Q[13].answer="SUDDEN";
        Q[14].answer="MEADOW";
        Q[15].answer="ENAMEL";
        Q[16].answer="WASABI";
        Q[17].answer="CHEESE";
        Q[18].answer="EMBLEM";
        Q[19].answer="ALARAM";
        Q[20].answer="PASS";
        Q[21].answer="SALUTE";
        Q[22].answer="EEL";
        Q[23].answer="REMEMBER";
        Q[24].answer="MUSEUM";

        //Answer Co-ordinates
        Q[0].start.first=1;
        Q[0].start.second=1;
        Q[0].end.first=6;
        Q[0].end.second=1;

        Q[1].start.first=1;
        Q[1].start.second=3;
        Q[1].end.first=6;
        Q[1].end.second=3;

        Q[2].start.first=1;
        Q[2].start.second=6;
        Q[2].end.first=5;
        Q[2].end.second=6;

        Q[3].start.first=1;
        Q[3].start.second=8;
        Q[3].end.first=7;
        Q[3].end.second=8;

        Q[4].start.first=1;
        Q[4].start.second=10;
        Q[4].end.first=8;
        Q[4].end.second=10;

        Q[5].start.first=1;
        Q[5].start.second=12;
        Q[5].end.first=6;
        Q[5].end.second=12;

        Q[6].start.first=2;
        Q[6].start.second=6;
        Q[6].end.first=2;
        Q[6].end.second=13;

        Q[7].start.first=3;
        Q[7].start.second=1;
        Q[7].end.first=3;
        Q[7].end.second=3;

        Q[8].start.first=4;
        Q[8].start.second=3;
        Q[8].end.first=4;
        Q[8].end.second=8;

        Q[9].start.first=4;
        Q[9].start.second=10;
        Q[9].end.first=4;
        Q[9].end.second=13;

        Q[10].start.first=6;
        Q[10].start.second=1;
        Q[10].end.first=6;
        Q[10].end.second=5;

        Q[11].start.first=6;
        Q[11].start.second=4;
        Q[11].end.first=13;
        Q[11].end.second=4;

        Q[12].start.first=6;
        Q[12].start.second=7;
        Q[12].end.first=6;
        Q[12].end.second=13;

        Q[13].start.first=1;
        Q[13].start.second=1;
        Q[13].end.first=1;
        Q[13].end.second=6;

        Q[14].start.first=8;
        Q[14].start.second=1;
        Q[14].end.first=8;
        Q[14].end.second=6;

        Q[15].start.first=8;
        Q[15].start.second=2;
        Q[15].end.first=13;
        Q[15].end.second=2;

        Q[16].start.first=8;
        Q[16].start.second=6;
        Q[16].end.first=13;
        Q[16].end.second=6;

        Q[17].start.first=8;
        Q[17].start.second=11;
        Q[17].end.first=13;
        Q[17].end.second=11;

        Q[18].start.first=8;
        Q[18].start.second=13;
        Q[18].end.first=13;
        Q[18].end.second=13;

        Q[19].start.first=9;
        Q[19].start.second=8;
        Q[19].end.first=13;
        Q[19].end.second=8;	

        Q[20].start.first=10;
        Q[20].start.second=1;
        Q[20].end.first=10;
        Q[20].end.second=4;

        Q[21].start.first=10;
        Q[21].start.second=6;
        Q[21].end.first=10;
        Q[21].end.second=11;

        Q[22].start.first=11;
        Q[22].start.second=11;
        Q[22].end.first=11;
        Q[22].end.second=13;

        Q[23].start.first=12;
        Q[23].start.second=1;
        Q[23].end.first=12;
        Q[23].end.second=8;

        Q[24].start.first=13;
        Q[24].start.second=8;
        Q[24].end.first=13;
        Q[24].end.second=13;

        //hint1
        Q[0].hint1="the top of a mountain";
        Q[1].hint1="The state of not being protected from injury, harm, or evil";
        Q[2].hint1=" A place, employment, status, or activity for which a person or thing is best fitted";
        Q[3].hint1="To accept (something or someone) readily or gladly";
        Q[4].hint1="an adult male horse, especially one that is used for breeding";
        Q[5].hint1="A path or trail that is made by people or animals";
        Q[6].hint1="not fully grown or developed";
        Q[7].hint1="An adult male human being";
        Q[8].hint1="To bring many things together";
        Q[9].hint1="A combination of circumstances, events, etc., operating by chance to bring good or ill to a person";
        Q[10].hint1="The human body apart from the head, neck, arms, and legs";
        Q[11].hint1="to avoid answering a question or dealing with a problem";
        Q[12].hint1="an occasion when the moon or the sun seems to completely or partly";
        Q[13].hint1="something that happens quickly, without warning, or unexpectedly.";
        Q[14].hint1="a field of grass, often with wild flowers, herbs, and other non-woody plants";
        Q[15].hint1="the hard white outer covering of a tooth";
        Q[16].hint1=" a Japanese's plant";
        Q[17].hint1="a type of food made from milk";
        Q[18].hint1="an object or symbol that represents something";
        Q[19].hint1="a sudden feeling of fear or worry";
        Q[20].hint1="to move past or to the other side of somebody/something";
        Q[21].hint1="something that shows respect for somebody";
        Q[22].hint1="A long, thin, snake-like fish with smooth, slippery skin";
        Q[23].hint1="to not forget to do what you have to do";
        Q[24].hint1="a building where collections of valuable and interesting objects are kept and shown to the public";
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
                if(ans2[i][j]==' ')
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
                if(ans2[i][j]==' ')
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
                ans2[i][j]=Q[x].answer[k];
                k++;
            }
            k=0;
        }
        else
        {
            j=Q[x].start.second;
            for(i=Q[x].start.first;i<=Q[x].end.first;i++)
            {
                ans2[i][j]=Q[x].answer[k];
                k++;
            }
            k=0;
        }
    }

    void display()
    {
    //0th row
        cout<<"     ___     ___\t"<<" ___\t ___\t ___\t ___"<<endl;
        int c=0;
        for(int i=0;i<13;i++)
        {
            if(i==0)
            {
                cout<<" _\x1b[4m \x1b[0m_|";
            }
            else if(i==1)
            {
                cout<<"_\x1b[4m1\x1b[0m_|";
            }
            else if(i==2)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==3)
            {
                cout<<"_\x1b[4m2\x1b[0m_|";
            }
            else if(i==4)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==6)
            {
                cout<<"_\x1b[4m3\x1b[0m_|";
            }
            else if(i==7 || i==9 || i==11)
            {
                cout<<"   |";
            }
            else if(i==8)
            {
                cout<<"_\x1b[4m4\x1b[0m_|";
            }
            else if(i==10)
            {
                cout<<"_\x1b[4m5\x1b[0m_|";
            }
            else if(i==12)
            {
                cout<<"_\x1b[4m6\x1b[0m_|"<<endl;
            }
        }

        //1st row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m14\x1b[0m_|";
            }
            else if(i==7 || i==9 || i==11)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==13)
            {
                cout<<"_\x1b[4m \x1b[0m_";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[1][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;
        
        //2nd row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<" _\x1b[4m \x1b[0m_|";
            }
            else if(i==2)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==4)
            {
                cout<<"   |";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m7\x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[2][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //3rd row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|_\x1b[4m8\x1b[0m_|";
            }
            else if(i==7 || i==9 || i==11)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==4 || i==13)
            {
                if(i==13)
                {
                    cout<<"_\x1b[4m \x1b[0m_"<<endl;
                }
                else{
                    cout<<"_\x1b[4m \x1b[0m__";
                }
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[3][c]<<"\x1b[0m_|";
            }
            c++;
        }

        //4th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"    |";
            }
            else if(i==2)
            {
                cout<<"_\x1b[4m9\x1b[0m_|";
            }
            else if(i==9)
            {
                cout<<"_\x1b[4m10\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[4][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //5th row
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<" _\x1b[4m \x1b[0m_|";
            }
            else if(i==4)
            {
                cout<<"_\x1b[4m12\x1b[0m|";
            }
            else if(i==2 || i==5 || i==7 || i==9 || i==11)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==13)
            {
                cout<<"_\x1b[4m \x1b[0m_"<<endl;
            }
            else{
                cout<<"_\x1b[4m"<<ans2[5][c]<<"\x1b[0m_|";
            }
            c++;
        }
        
        //6th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m11\x1b[0m_|";
            }
            else if(i==6)
            {
                cout<<"_\x1b[4m13\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[6][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //7th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<" _\x1b[4m \x1b[0m__";
            }
            else if(i==1 || i==3 || i==5)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==7 || i==9 || i==12)
            {
                cout<<"   |";
            }
            else if(i==2)
            {
                cout<<"_\x1b[4m16\x1b[0m|";
            }
            else if(i==6)
            {
                cout<<"_\x1b[4m17\x1b[0m|";
            }
            else if(i==11)
            {
                cout<<"_\x1b[4m18\x1b[0m|";
            }
            else if(i==13)
            {
                cout<<"_\x1b[4m19\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[7][c]<<"\x1b[0m_|";
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
                cout<<"|\x1b[4m15\x1b[0m_|";
            }
            else if(i==8)
            {
                cout<<"_\x1b[4m20\x1b[0m|";
            }
            else if(i==7 || i==9 || i==12)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[8][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //9th row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<14;i++)
        {
            if(i==3 || i==5 || i==7)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==9)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==10)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==12)
            {
                cout<<"   |";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[9][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //10th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m21\x1b[0m_|";
            }
            else if(i==5)
            {
                cout<<"_\x1b[4m22\x1b[0m|";
            }
            else if(i==12)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[10][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //11th row
        c=2;
        cout<<" _\x1b[4m \x1b[0m___\x1b[4m \x1b[0m_|";
        for(int i=2;i<14;i++)
        {
            if(i==3 || i==5 || i==7)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else if(i==9)
            {
                cout<<"   |";
            }
            else if(i==10)
            {
                cout<<"_\x1b[4m23\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[11][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //12th row
        c=0;
        for(int i=0;i<14;i++)
        {
            if(i==0)
            {
                cout<<"|\x1b[4m24\x1b[0m_|";
            }
            else if(i==9)
            {
                cout<<"_\x1b[4m \x1b[0m__";
            }
            else if(i==10 || i==12)
            {
                cout<<"_\x1b[4m \x1b[0m_|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[12][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;

        //13th row
        c=2;
        cout<<"\t|";
        for(int i=2;i<14;i++)
        {
            if(i==3 || i==5)
            {
                cout<<"   |";
            }
            else if(i==7)
            {
                cout<<"_\x1b[4m25\x1b[0m|";
            }
            else{
                cout<<"_\x1b[4m"<<ans2[13][c]<<"\x1b[0m_|";
            }
            c++;
        }
        cout<<endl;
        cout<<"EASY"<<endl;
        cout<<endl;        
        cout<<"2.Hazard"<<endl;
        cout<<"3.Brother of one's father"<<endl;
        cout<<"6.What a police bloodhound does"<<endl;
        // cout<<"8.Adult male person"<<endl;
        // cout<<"14.Unexpectedly quick"<<endl;
        // cout<<"18.Dairy product"<<endl;
        // cout<<"20.Clock that wakes a sleeper at a present time"<<endl;
        // cout<<"21.Succeed in an examination"<<endl;       
        
        cout<<endl;
        cout<<"MEDIUM"<<endl<<endl;
        cout<<"4.Clasp another person in arms"<<endl;
        cout<<"9.Assemble"<<endl;
        cout<<"10.Chance, fortune"<<endl;
        // cout<<"15.Adult male horse"<<endl;        
        // cout<<"16.Substance covering the crown of a tooth"<<endl;
        // cout<<"22.Military greeting"<<endl;
        // cout<<"23.Snake like fish"<<endl;
        // cout<<"24.Keep information in mind"<<endl;
        // cout<<"25.Depository for displaying objects of historical interest"<<endl;
        
        cout<<endl;
        cout<<"HARD"<<endl<<endl;
        cout<<"1.Apex"<<endl;
        cout<<"3.Wall recess"<<endl;
        cout<<"7.Not fully developed, juvenile"<<endl;
        // cout<<"11.Body trunk"<<endl;
        // cout<<"12.A physical motion to avoid or dodge something"<<endl;
        // cout<<"13.One celetial body obscures another"<<endl;
        // cout<<"15.A feild which has grass and flowers growing"<<endl;        
        // cout<<"17.Sushi condiment"<<endl;
        // cout<<"19.Insignia"<<endl;
        cout<<endl;
    }
};

// int main()
// {
//     char ans2[14][14];
//     for(int i=0;i<14;i++)
//     {
//         for(int j=0;j<14;j++)
//         {
//             ans2[i][j]=' ';
//         }
//     }
//     /*char x='a';
//     for(int i=0;i<14;i++)
//     {
//         for(int j=0;j<14;j++)
//         {
//             ans2[i][j]=x;
//             x++;
//         }
//         x='a';
//     }*/

// }