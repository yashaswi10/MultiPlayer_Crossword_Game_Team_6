#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <chrono>
#include <pthread.h>
#include "login.h"
#include "Board1.h"
#include "Board2.h"
#include "Board3.h"
using namespace std;

class WordQuest1
{
public:
    struct Player 
    {
        string username;
        int PNo;
        int score;
    }P[4];

    board1 B1;
    board2 B2;
    board3 B3;
    int board_no;
    pthread_t thread1, thread2, thread3, thread4;
    pthread_mutex_t mutex;
    bool gameover=false;
    int questions_done=0;

    WordQuest1(int n)
    {
        board_no=n;
        pthread_mutex_init(&mutex, nullptr);
        for (int i=0;i<4;i++)
        {
            P[i].PNo=i;
            P[i].score=0;
        }
    }
    
    Player find_player(const int& pnoToFind) 
    {
        ifstream readFile("scores.csv");
        Player temp;
        string line;
        bool found = false;

        while (getline(readFile, line)) {
            int pNo;
            string username;
            int score;

            size_t commaPos1 = line.find(',');
            pNo = stoi(line.substr(0, commaPos1));

            size_t commaPos2 = line.find(',', commaPos1 + 1);
            username = line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1);

            score = stoi(line.substr(commaPos2 + 1));

            if (pNo == pnoToFind) {
                temp.PNo = pNo;
                temp.username = username;
                temp.score = score;
                found = true;
                break; 
            }
        }

        if (!found) {
            temp.PNo = -1;
        }

        readFile.close();
        return temp;
        readFile.close();
        return temp;
    }

    void updatePlayerScore(int pno, int QNo ,int value, string inc_or_dec) 
    {
        int points,t,r;
        Player curr_player;
        if (value==0)
        {
            curr_player=find_player(pno);
            if (board_no==1)
            {
                t=B1.qm[(curr_player.PNo)-1][QNo];
                r=B1.Q[QNo].points;
            }
            else if (board_no==2)
            {
                t=B2.qm[(curr_player.PNo)-1][QNo];
                r=B2.Q[QNo].points;
            }
            else if (board_no==3)
            {
                t=B3.qm[(curr_player.PNo)-1][QNo];
                r=B3.Q[QNo].points;
            }
            if (t==0)
                points=r;
            else if (t==10)
                points=r-10;
            else if (t==20)
                points=r-20;
        }
        else
        {
            points=value;
        }


        ifstream readFile("scores.csv");
        vector<Player> players;
        string line;
        while (getline(readFile, line)) 
        {
            string pNo, username, score;

            size_t pos = 0;
            size_t commaPos1 = line.find(',', pos);
            pNo = line.substr(pos, commaPos1 - pos);
            pos = commaPos1 + 1;

            size_t commaPos2 = line.find(',', pos);
            username = line.substr(pos, commaPos2 - pos);
            pos = commaPos2 + 1;

            score = line.substr(pos);
            int Pno = stoi(line.substr(0, commaPos1));
            int Score = stoi(line.substr(commaPos2 + 1));
            Player temp;
            temp.PNo=Pno;
            temp.score=Score;
            temp.username=username;
            players.push_back(temp);

        }
        readFile.close();

        for (Player& p : players) 
        {
            if (p.PNo == curr_player.PNo) 
            {
                if (inc_or_dec=="increase")
                {
                    p.score += points; 
                    break;
                }
                if (inc_or_dec=="deccrease")
                {
                    p.score -= points; 
                    break;
                }
            }
        }

        ofstream fileOut("scores.csv"); 
        for (const Player& p : players) 
        {
            fileOut << p.PNo << "," <<p.username << "," << p.score << "\n";
        }
        fileOut.close();
    }

    void check_question(int QNo)
    {
        string answer;
        if (board_no==1)
        {
            answer=B1.Q[QNo].answer;
            for (int i=0;i<4;i++)
            {
                if (B1.qm[i][QNo]!=20)
                {
                    return;
                }
            }
        }
        else if (board_no==2)
        {
            answer=B2.Q[QNo].answer;
            for (int i=0;i<4;i++)
            {
                if (B2.qm[i][QNo]!=20)
                {
                    return;
                }
            }
        }
        else if (board_no==3)
        {
            answer=B3.Q[QNo].answer;
            for (int i=0;i<4;i++)
            {
                if (B3.qm[i][QNo]!=20)
                {
                    return;
                }
            }
        }
        cout<<"\nAll Players attempted to answer Word"<<QNo+1<<" taking all 2 hints...\nThe correct word is: "<<answer<<endl;
        cout<<"\nNo player can attempt this question now....!\n";
        questions_done++;

        if (board_no==1)
        {
            B1.update_board(QNo);
            B1.qm[0][QNo]=100;
        }
        else if (board_no==2)
        {
            B2.update_board(QNo);
            B2.qm[0][QNo]=100;
        }
        else if (board_no==3)
        {
            B3.update_board(QNo);
            B3.qm[0][QNo]=100;
        }

    }

    void print_scores()
    {
        ifstream readFile("scores.csv");
        string line;

        cout <<setw(93)<<setfill(' ')<< "+--------+---------------+--------+" << endl;
        cout <<setw(60)<<setfill(' ')<<"| " << "PNo" << setw(6) << " | "  << "Username" << setw(8)<< " | " << "Score" << setw(3) << " |" << endl;
        cout <<setw(93)<<setfill(' ')<< "+--------+---------------+--------+" << endl;

        while (getline(readFile, line)) {
            size_t pos1 = line.find(',');
            if (pos1 != string::npos) {
                string pno = line.substr(0, pos1);

                size_t pos2 = line.find(',', pos1 + 1);
                if (pos2 != string::npos) {
                    string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    string scoreStr = line.substr(pos2 + 1);

                    int score = stoi(scoreStr);

                    // Printing formatted table rows
                    cout <<setw(60)<<setfill(' ')<< "| " <<  pno <<setw(8) << " | " <<  username <<setw(12) << " | " <<  score <<setw(6) << " |" << endl;
                }
            }
        }

        readFile.close();

        // Printing the bottom border of the table
        cout <<setw(93)<<setfill(' ')<< "+--------+---------------+--------+" << endl;

        // Finding the user with the highest score
        ifstream file("scores.csv");
        string line1;
        string highestUser;
        int highestScore = -1;

        if (file.is_open()) {
            while (getline(file, line1)) {
                size_t pos1 = line1.find(',');
                if (pos1 != string::npos) {
                    string pno = line1.substr(0, pos1);

                    size_t pos2 = line1.find(',', pos1 + 1);
                    if (pos2 != string::npos) {
                        string username = line1.substr(pos1 + 1, pos2 - pos1 - 1);
                        string scoreStr = line1.substr(pos2 + 1);

                        int score = stoi(scoreStr);

                        if (score > highestScore) {
                            highestScore = score;
                            highestUser = pno + ". " + username;
                        }
                    }
                }
            }
            file.close();
        }
        cout<<endl;
        cout << setw(90)<<setfill(' ')<<"User with the highest score: \n" <<setw(64)<<setfill(' ')<<"\033[1m"<< highestUser <<"\033[0m"<< " with a score of " << highestScore << endl;
        cout<<endl;
    }
    
    void get_hint(int PNo, const int& QNo)
    {
        PNo--;
        int t;
        string hint1;
        if (board_no==1)
        {
            t=B1.qm[PNo][QNo];
            hint1=B1.Q[QNo].hint1;
        }
        else if (board_no==2)
        {
            t=B2.qm[PNo][QNo];
            hint1=B2.Q[QNo].hint1;
        }
        else if (board_no==3)
        {
            t=B3.qm[PNo][QNo];
            hint1=B3.Q[QNo].hint1;
        }

        if (t==0)
        {
            if (board_no==1)
                B1.qm[PNo][QNo]=10;
            else if (board_no==2)
                B2.qm[PNo][QNo]=10;
            else if (board_no==3)
                B3.qm[PNo][QNo]=10;

            cout<<"\nFirst Hint for the word "<<QNo+1<<" is: "<<hint1<<endl;
        }
        else if (t==10)
        {
            if (board_no==1)
                B1.qm[PNo][QNo]=20;
            else if (board_no==2)
                B2.qm[PNo][QNo]=20;
            else if (board_no==3)
                B3.qm[PNo][QNo]=20;

            cout<<"\nSecond Hint for the word "<<QNo+1<<" :"<<endl;

            if (board_no==1)
                B1.queHint2(QNo);
            else if (board_no==2)
                B2.queHint2(QNo);
            else if (board_no==3)
                B3.queHint2(QNo);
            
        }
        else if (t==20)
        {
            cout<<"\nNo more hints left for this word....!"<<endl;
        }
    }

    int choose_question(int PNo)
    {
        PNo--;
        int QNo;
        int done=0;
        while(done==0)
        {
            cout<<"\nEnter the question_no you want to answer: ";
            cin>>QNo;
            QNo--;
            done=1;
            if (board_no==1)
            {
                for (int i=0;i<3;i++)
                {
                    if (B1.qm[i][QNo]==100)
                    {
                        cout<<"\nQuestion already done....Choose another question!\n "<<endl;
                        done=0;
                    }
                }
            }
            else if (board_no==2)
            {
                for (int i=0;i<3;i++)
                {
                    if (B2.qm[i][QNo]==100)
                    {
                        cout<<"\nQuestion already done....Choose another question!\n "<<endl;
                        done=0;
                    }
                }
            }
            else if (board_no==3)
            {
                for (int i=0;i<3;i++)
                {
                    if (B3.qm[i][QNo]==100)
                    {
                        cout<<"\nQuestion already done....Choose another question!\n "<<endl;
                        done=0;
                    }
                }
            }
            
        }

        if (board_no==1)
        {
            if (B1.qm[PNo][QNo]==-1)
            B1.qm[PNo][QNo]=0;
        }
        else if (board_no==2)
        {
            if (B2.qm[PNo][QNo]==-1)
            B2.qm[PNo][QNo]=0;
        }
        else if (board_no==3)
        {
            if (B3.qm[PNo][QNo]==-1)
            B3.qm[PNo][QNo]=0;
        }

        return QNo;
    }


    void game(int PNo)
    {
        while (!gameover) 
        {
            pthread_mutex_lock(&mutex);   
            if (gameover) 
            {
                pthread_mutex_unlock(&mutex);
                break;
            }
            if (board_no==1)
                B1.display();
            else if (board_no==2)
                B2.display();
            else if (board_no==3)
                B3.display();
            

            //Choosing a question
            int QNo;
            cout<<"\nPlayer "<<PNo<<"'s turn...."<<endl;
            QNo=choose_question(PNo);

            //Hints
            bool wantsHint;
            cout << "\nDo you want a hint? (1 for Yes, 0 for No): ";
            cin >> wantsHint;
            if (wantsHint)
                get_hint(PNo,QNo);

        

            //Answer
            auto start = chrono::high_resolution_clock::now(); 
            string answer;
            cout << "\nEnter your answer: ";
            cin >> answer;
            auto end = chrono::high_resolution_clock::now(); 
            auto duration = chrono::duration_cast<chrono::seconds>(end - start);

            if (duration.count() >= 10) 
            {
                cout << "Player " << PNo << " timed out! ";
                //cout << "Player " << PNo%4 +1 << " gets the chance!\n";
                //PNo=PNo%4+1;
            }
            else
            {
                string correct_answer;
                if (board_no==1)
                    correct_answer=B1.Q[QNo].answer;
                else if (board_no==2)
                    correct_answer=B2.Q[QNo].answer;
                else if (board_no==3)
                    correct_answer=B3.Q[QNo].answer;

                if (answer == correct_answer) 
                {
                    cout << "Correct!" << endl;
                    //score addition
                    updatePlayerScore(PNo, QNo,0, "increase");
                    
                    if (board_no==1)
                    {
                        B1.update_board(QNo);
                        B1.qm[PNo-1][QNo]=100;
                    }
                    else if (board_no==2)
                    {
                        B2.update_board(QNo);
                        B2.qm[PNo-1][QNo]=100;
                    }
                    else if (board_no==3)
                    {
                        B3.update_board(QNo);
                        B3.qm[PNo-1][QNo]=100;
                    }
                    
                    questions_done++;
                    if (questions_done==28)
                    {
                        cout<<"\nGame completed......!!!!!!"<<endl;
                        void print_scores();
                        gameover = true;  
                        pthread_mutex_unlock(&mutex);   
                        break;
                    }
                } 
                else 
                {
                    check_question(QNo);
                    if (questions_done==28)
                    {
                        cout<<"\nGame completed......!!!!!!"<<endl;
                        void print_scores();
                        gameover = true;  
                        pthread_mutex_unlock(&mutex);   
                        break;
                    }
                    bool tryAgain;
                    cout<<"\nIncorrect Answer. Do you want to try again? "<<endl<<"(...You will lose 10 points from your score...)"<<endl<<"\nEnter 1 for Yes, 0 for No: ";
                    cin>>tryAgain;
                    if (tryAgain) 
                    {
                        //score reduction by 10
                        updatePlayerScore(PNo,QNo,10,"decrease");

                        bool wanthint;
                        cout << "\nDo you want a hint? (1 for Yes, 0 for No): ";
                        cin >> wanthint;
                        if (wanthint)
                            get_hint(PNo,QNo);
                        
                        cout<<"\nEnter your answer again: ";
                        cin>>answer;

                        if (answer == correct_answer) 
                        {
                            cout << "Correct!" << endl;
                            updatePlayerScore(PNo,QNo,0,"increase");

                            if (board_no==1)
                            {
                                B1.update_board(QNo);
                                B1.qm[PNo-1][QNo]=100;
                            }
                            else if (board_no==2)
                            {
                                B2.update_board(QNo);
                                B2.qm[PNo-1][QNo]=100;
                            }
                            else if (board_no==3)
                            {
                                B3.update_board(QNo);
                                B3.qm[PNo-1][QNo]=100;
                            }

                            questions_done++;
                            if (questions_done==28)
                            {
                                cout<<"Game completed......!!!!!!"<<endl;
                                void print_scores();
                                gameover = true;  
                                pthread_mutex_unlock(&mutex);   
                                break;
                            }
                        }
                        else
                        {
                            cout<<"Incorrect answer";
                            check_question(QNo);
                            if (questions_done==28)
                            {
                                cout<<"Game completed......!!!!!!"<<endl;
                                void print_scores();
                                gameover = true;  
                                pthread_mutex_unlock(&mutex);   
                                break;
                            }
                        }

                    }
                }
            }
            cout<<"\nPlayer"<<PNo<<"'s turn is completed"<<endl;
            cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"; 
            PNo=PNo%4+1;
            pthread_mutex_unlock(&mutex);
        }

    }

    void* player1Move() 
    {
        game(1);
        return nullptr;
    }

    void* player2Move() 
    {
        game(2);
        return nullptr;
    }

    void* player3Move() 
    {
        game(3);
        return nullptr;
    }

    void* player4Move() 
    {
        game(4);
        return nullptr;
    }


    void startGame() 
    {
        pthread_create(&thread1, nullptr, &WordQuest1::player1MoveHelper, this); 
        pthread_join(thread1, nullptr);   
        
        pthread_create(&thread2, nullptr, &WordQuest1::player2MoveHelper, this);  
        pthread_join(thread2, nullptr); 

        pthread_create(&thread3, nullptr, &WordQuest1::player3MoveHelper, this); 
        pthread_join(thread3, nullptr);   
        
        pthread_create(&thread4, nullptr, &WordQuest1::player4MoveHelper, this);  
        pthread_join(thread4, nullptr); 

        if (questions_done==28)
        {
            cout<<"\nGame completed......!!!!!!"<<endl;
            void print_scores();
        }
    }
    
    
    static void* player1MoveHelper(void* context)  
    {
        reinterpret_cast<WordQuest1*>(context)->player1Move();
        return nullptr;
    }

    static void* player2MoveHelper(void* context) 
    {
        reinterpret_cast<WordQuest1*>(context)->player2Move();
        return nullptr;
    }

    static void* player3MoveHelper(void* context)  
    {
        reinterpret_cast<WordQuest1*>(context)->player3Move();
        return nullptr;
    }

    static void* player4MoveHelper(void* context) 
    {
        reinterpret_cast<WordQuest1*>(context)->player4Move();
        return nullptr;
    }


    ~WordQuest1()
    {
        pthread_mutex_destroy(&mutex);
    }

};


int main()
{
    cout<<endl;
    cout<<setw(80)<<setfill('-')<<"WORD QUEST"<<setw(80)<<setfill('-');
    cout<<"\n"<<endl;
    cout<<setw(77)<<setfill(' ')<<"RULES"<<endl;
    cout<<"\n1.Time Constraint: Players have 10 seconds to answer each question, emphasizing quick thinking."<<endl;
    cout<<"2.Two Attempts Limit: Each player can attempt a question twice(during every turn), additional attempts are not allowed."<<endl;
    cout<<"3.Hint Penalty: Taking one hint deducts 10 points; taking two hints results in a 20-point deduction."<<endl;
    cout<<"4.Strategic Choices: Players must decide when to use hints, as it affects their overall score."<<endl;
    cout<<"5.Scoring System: Points are earned for correct answers, but penalties for incorrect attempts impact the final score.\n"<<endl;
    cout<<setw(265)<<setfill('-');
    cout<<endl;
    //choosing board
    cout<<"\nChoose a board:\n1. General\n2. General(Hard)\n3. Science\nEnter the number of the board you want to choose: ";
    int boardNo;
    cin>>boardNo;
    while (boardNo>=4 || boardNo<=0)
    {
        cout<<"\nInvalid choice.....Please enter again: ";
        cin>>boardNo;
    }
    WordQuest1 wordgame(boardNo);
    
    cout<<"Board choosed.........!!\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;

    //user details
    cout<<setw(87)<<setfill(' ')<<"Enter User Information"<<endl;
    const string userfile="user_info.csv";
    
    string username1,username2,username3,username4;
    cout<<"\nPlayer1: ";
    username1=signin(userfile);
    wordgame.P[0].username=username1;

    cout<<"\nPlayer2: ";
    username2=signin(userfile);
    wordgame.P[1].username=username2;

    cout<<"\nPlayer3: ";
    username3=signin(userfile);
    wordgame.P[2].username=username3;

    cout<<"\nPlayer4: ";
    username4=signin(userfile);
    wordgame.P[3].username=username4;
    cout<<endl;
    cout<<"\nPlayers login completed.........!!"<<endl;

    const string scorefile="scores.csv";
    int p=30;
    ofstream file("scores.csv", ios::app);
    file<<1<<","<<username1<<","<<p<<"\n";
    file<<2<<","<<username2<<","<<p<<"\n";
    file<<3<<","<<username3<<","<<p<<"\n";
    file<<4<<","<<username4<<","<<p<<"\n";
    file.close();

    wordgame.startGame();
    return 0;
}