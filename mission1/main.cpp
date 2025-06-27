#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectBreakSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);
void displayCarType();
void displayEngine();
void displayBreakSystem();
void displaySteeringSystem();
void userUI();
bool isValidInput(int answer);
bool flowControl(int answer);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BreakSystem_Q,
    SteeringSystem_Q,
    RunTest_Q,
};

enum CarType
{
    Sedan = 1,
    SUV,
    Truck,

    CarTypeLen
};

enum Engine
{
    GM = 1,
    Toyota,
    WIA,

    EngineLen
};

enum BreakSystem
{
    Mando = 1,
    Continental,
    Bosch_b,

    BreakSystemLen
};

enum SteeringSystem
{
    Bosch_s = 1,
    Mobis,

    SteeringSystemLen
};

string car_type[10] = { "", "Sedan", "SUV", "Truck" };
string engine[10] = { "", "GM", "TOYOTA", "WIA", "고장난 엔진"};
string break_system[10] = { "", "MANDO", "CONTINENTAL", "BOSCH_B"};
string steering_system[10] = { "", "BOSCH_S", "MOBIS"};
int step = CarType_Q;
string buf, context;

int main()
{
    while (1)
    {
        userUI();

        if (buf=="exit")
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        int answer;
        try {
            answer = std::stoi(context);
        }
        catch (std::invalid_argument&) {
            // 입력받은 문자가 숫자가 아니라면
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }
        if (isValidInput(answer)) {
            continue;
        }
        if (flowControl(answer)) {
            continue;
        }

        
    }
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;
    printf("차량 타입으로 %s을(를) 선택하셨습니다.\n", car_type[answer]);
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;
    printf("%s 엔진을 선택하셨습니다.\n", engine[answer]);
}

void selectBreakSystem(int answer)
{
    stack[BreakSystem_Q] = answer;
    printf("%s 제동장치를 선택하셨습니다.\n", break_system[answer]);
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    printf("%s 조항장치를 선택하셨습니다.\n", steering_system[answer]);
}

int isValidCheck()
{
    if (stack[CarType_Q] == Sedan && stack[BreakSystem_Q] == Continental)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == Toyota)
    {
        return false;
    }
    else if (stack[CarType_Q] == Truck && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == Truck && stack[BreakSystem_Q] == Mando)
    {
        return false;
    }
    else if (stack[BreakSystem_Q] == Bosch_b && stack[SteeringSystem_Q] != Bosch_s)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (stack[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printf("Car Type : %s\n", car_type[stack[CarType_Q]]);
            printf("Engine : %s\n", engine[stack[Engine_Q]]);
            printf("Break System : %s\n", break_system[stack[BreakSystem_Q]]);
            printf("SteeringSystem : %s\n", steering_system[stack[SteeringSystem_Q]]);

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == Sedan && stack[BreakSystem_Q] == Continental)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == Toyota)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == Truck && stack[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == Truck && stack[BreakSystem_Q] == Mando)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (stack[BreakSystem_Q] == Bosch_b && stack[SteeringSystem_Q] != Bosch_s)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

void displayCarType() {
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");

    for (int i = 1; i < CarTypeLen; i++) {
        printf("%d, %s\n", i, car_type[i]);
    }
    return;
}

void displayEngine() {
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < EngineLen; i++) {
        printf("%d, %s\n", i, engine[i]);
    }
    return;
}

void displayBreakSystem() {
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < BreakSystemLen; i++) {
        printf("%d, %s\n", i, break_system[i]);
    }
    return;
}

void displaySteeringSystem() {
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < SteeringSystemLen; i++) {
        printf("%d, %s\n", i, steering_system[i]);
    }
    return;
}

void userUI() {
    if (step == CarType_Q)
    {
        displayCarType();
    }
    else if (step == Engine_Q)
    {
        displayEngine();
    }
    else if (step == BreakSystem_Q)
    {
        displayBreakSystem();
    }
    else if (step == SteeringSystem_Q)
    {
        displaySteeringSystem();
    }
    else if (step == RunTest_Q)
    {
        printf(CLEAR_SCREEN);
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");

    std::getline(std::cin, buf);

    // 엔터 개행문자 제거
    std::istringstream iss(buf);
    iss >> context;

}

bool isValidInput(int answer) {
    if (step == CarType_Q && !(answer >= 1 && answer < CarTypeLen))
    {
        printf("ERROR :: 차량 타입은 1 ~ %d 범위만 선택 가능\n", CarTypeLen - 1);
        delay(800);
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer < EngineLen))
    {
        printf("ERROR :: 엔진은 1 ~ %d 범위만 선택 가능\n", EngineLen - 1);
        delay(800);
        return true;
    }

    if (step == BreakSystem_Q && !(answer >= 0 && answer < BreakSystemLen))
    {
        printf("ERROR :: 제동장치는 1 ~ %d 범위만 선택 가능\n", BreakSystemLen - 1);
        delay(800);
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer < SteeringSystemLen))
    {
        printf("ERROR :: 조향장치는 1 ~ %d 범위만 선택 가능\n", SteeringSystemLen - 1);
        delay(800);
        return true;
    }

    if (step == RunTest_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return true;
    }
    return false;
}

bool flowControl(int answer) {
    // 처음으로 돌아가기
    if (answer == 0 && step == RunTest_Q)
    {
        step = CarType_Q;
        return true;
    }

    // 이전으로 돌아가기
    if (answer == 0 && step >= 1)
    {
        step -= 1;
        return true;
    }

    if (step == CarType_Q)
    {
        selectCarType(answer);
        delay(800);
        step = Engine_Q;
    }
    else if (step == Engine_Q)
    {
        selectEngine(answer);
        delay(800);
        step = BreakSystem_Q;
    }
    else if (step == BreakSystem_Q)
    {
        selectBreakSystem(answer);
        delay(800);
        step = SteeringSystem_Q;
    }
    else if (step == SteeringSystem_Q)
    {
        selectSteeringSystem(answer);
        delay(800);
        step = RunTest_Q;
    }
    else if (step == RunTest_Q && answer == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (step == RunTest_Q && answer == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
    return false;
}

#endif