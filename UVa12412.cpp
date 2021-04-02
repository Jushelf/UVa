#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

void menu();
void Add();
void Remove();
void Query();
void ShowRanking();
void ShowStatistics();

#define epsilon 1e-5//??? bad data

struct student
{
    char SID[15];
    int CID;
    char name[15];
    int Chinese, Mathematics, English, Programming;
    int rank;
    int totalScore;
    double averageScore;
    int passNum;

    void printInfo()
    {
        printf("%d %s %d %s %d %d %d %d %d %.2lf\n",
               rank, SID, CID, name, Chinese, Mathematics,
               English, Programming, totalScore, averageScore + epsilon);
    }

    void computeScore()
    {
        totalScore = Chinese + Mathematics + English + Programming;
        averageScore = totalScore / 4.0;
        passNum = (Chinese >= 60) + (Mathematics >= 60) + (English >= 60) + (Programming >= 60);
    }
};

struct classInfo
{
    int number;
    int totalChineseScore;
    int passChinese;
    int totalMathematicsScore;
    int passMathematics;
    int totalEnglishScore;
    int passEnglish;
    int totalProgrammingScore;
    int passProgramming;

    int pass[5];

    classInfo():number(0), totalChineseScore(0), passChinese(0),
    totalMathematicsScore(0), passMathematics(0),
    totalEnglishScore(0), passEnglish(0),
    totalProgrammingScore(0), passProgramming(0),
    pass{}
    {}

    void addStudent(const student & stu)
    {
        number++;

        totalChineseScore += stu.Chinese;
        totalMathematicsScore += stu.Mathematics;
        totalEnglishScore += stu.English;
        totalProgrammingScore += stu.Programming;

        passChinese += (stu.Chinese >= 60);
        passMathematics += (stu.Mathematics >= 60);
        passEnglish += (stu.English >= 60);
        passProgramming += (stu.Programming >= 60);

        for (int i = 1; i < stu.passNum; ++i)
        {
            pass[i]++;
        }

        pass[stu.passNum]++;
    }

    void removeStudent(const student & stu)
    {
        number--;

        totalChineseScore -= stu.Chinese;
        totalMathematicsScore -= stu.Mathematics;
        totalEnglishScore -= stu.English;
        totalProgrammingScore -= stu.Programming;

        passChinese -= (stu.Chinese >= 60);
        passMathematics -= (stu.Mathematics >= 60);
        passEnglish -= (stu.English >= 60);
        passProgramming -= (stu.Programming >= 60);

        for (int i = 1; i < stu.passNum; ++i)
        {
            pass[i]--;
        }

        pass[stu.passNum]--;
    }

    void printInfo()
    {
        printf("Chinese\nAverage Score: %.2lf\nNumber of passed students: %d\n"
               "Number of failed students: %d\n\n", totalChineseScore / (double)number + epsilon,
               passChinese, number - passChinese);

        printf("Mathematics\nAverage Score: %.2lf\nNumber of passed students: %d\n"
               "Number of failed students: %d\n\n", totalMathematicsScore / (double)number + epsilon,
               passMathematics, number - passMathematics);

        printf("English\nAverage Score: %.2lf\nNumber of passed students: %d\n"
               "Number of failed students: %d\n\n", totalEnglishScore / (double)number + epsilon,
               passEnglish, number - passEnglish);

        printf("Programming\nAverage Score: %.2lf\nNumber of passed students: %d\n"
               "Number of failed students: %d\n\n", totalProgrammingScore / (double)number + epsilon,
               passProgramming, number - passProgramming);

        printf("Overall:\n"
               "Number of students who passed all subjects: %d\n"
               "Number of students who passed 3 or more subjects: %d\n"
               "Number of students who passed 2 or more subjects: %d\n"
               "Number of students who passed 1 or more subjects: %d\n"
               "Number of students who failed all subjects: %d\n\n",
               pass[4], pass[3], pass[2], pass[1], pass[0]);
    }
} ClassInfo[25];

list<student> stuList;

void modifyRank(student &stu, bool add)
{
    if (add)
    {
        stu.rank = 1;

        for (auto & s : stuList)
        {
            if (s.totalScore < stu.totalScore)
            {
                s.rank++;
            }
            else if (s.totalScore > stu.totalScore)
            {
                stu.rank++;
            }
        }
    }
    else
    {
        for (auto & s : stuList)
        {
            if (s.totalScore < stu.totalScore)
            {
                s.rank--;
            }
        }
    }
}

int main()
{
    bool flag = true;
    int choice;
    while (flag)
    {
        menu();

        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                flag = false;
                break;
            case 1:
                Add();
                break;
            case 2:
                Remove();
                break;
            case 3:
                Query();
                break;
            case 4:
                ShowRanking();
                break;
            case 5:
                ShowStatistics();
                break;
            default:
                break;
        }
    }

    return 0;
}

void menu()
{
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n\n");
}

void Add()
{
    student temp;
    bool isDuplicated;
    while (true)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", temp.SID);
        if (strcmp(temp.SID, "0") == 0)
        {
            break;
        }
        else
        {
            scanf("%d%s%d%d%d%d", &temp.CID, temp.name,
                  &temp.Chinese,&temp.Mathematics, &temp.English, &temp.Programming);

            isDuplicated = false;
            for (auto stu : stuList)
            {
                if (strcmp(stu.SID, temp.SID) == 0)
                {
                    printf("Duplicated SID.\n");
                    isDuplicated = true;
                    break;
                }
            }

            if (!isDuplicated)
            {
                temp.computeScore();
                modifyRank(temp, true);
                ClassInfo[temp.CID].addStudent(temp);
                ClassInfo[0].addStudent(temp);
                stuList.push_back(temp);
            }
        }
    }
}

void Remove()
{
    char s[15];
    int n;
    while (true)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0)
        {
            break;
        }
        else
        {
            n = stuList.size();

            for (auto it = stuList.begin();  it != stuList.end(); )
            {
                if (strcmp(it->SID, s) == 0 || strcmp(it->name, s) == 0)
                {
                    modifyRank(*it, false);
                    ClassInfo[0].removeStudent(*it);
                    ClassInfo[it->CID].removeStudent(*it);
                    it = stuList.erase(it);
                }
                else
                {
                    it++;
                }
            }

            n -= stuList.size();

            printf("%d student(s) removed.\n", n);
        }
    }
}

void Query()
{
    char s[15];

    while (true)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0)
        {
            break;
        }
        else
        {
            for (auto & stu : stuList)
            {
                if (strcmp(stu.SID, s) == 0 || strcmp(stu.name, s) == 0)
                {
                    stu.printInfo();
                }
            }
        }
    }
}

void ShowRanking()
{
    printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}

void ShowStatistics()
{
    int CID;

    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%d", &CID);

    ClassInfo[CID].printInfo();
}
