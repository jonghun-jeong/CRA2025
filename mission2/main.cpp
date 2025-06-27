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
#include "Car.h"
using namespace std;

#define CLEAR_SCREEN "\033[H\033[2J"

Car car;

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
    car.SetCarType(answer);
    printf("차량 타입으로 %s을(를) 선택하셨습니다.\n",  car.GetCarTypeString());
}

void selectEngine(int answer)
{
    car.SetEngine(answer);
    printf("%s 엔진을 선택하셨습니다.\n", car.GetEngineString());
}

void selectBreakSystem(int answer)
{
    car.SetBreakSystem(answer);
    printf("%s 제동장치를 선택하셨습니다.\n", car.GetBreakSystemString());
}

void selectSteeringSystem(int answer)
{
    car.SetSteeringSystem(answer);
    printf("%s 조항장치를 선택하셨습니다.\n", car.GetSteeringSystemString());
}

//자동차의 동작 여부 확인
void runProducedCar()
{
    if (car.CarSelfTest() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (car.GetEngine() == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printf("Car Type : %s\n", car.GetCarTypeString());
            printf("Engine : %s\n", car.GetEngineString());
            printf("Break System : %s\n", car.GetBreakSystemString());
            printf("SteeringSystem : %s\n", car.GetSteeringSystemString());

            printf("자동차가 동작됩니다.\n");
        }
    }
}

//자동차 동작 전 사전 테스트
void testProducedCar()
{
    if (car.SedanBreakCheck())
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (car.SuvEngineCheck())
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (car.TruckEngineCheck())
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (car.TruckBreakCheck())
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (car.BoschSetCheck())
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

//자동차 타입에 대한 모든 선택지 제공 추후 추가를 위해 car class에서 가져옴
void displayCarType() {
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");

    for (int i = 1; i < car.CarTypeLen; i++) {
        printf("%d, %s\n", i, car.car_type_list[i]);
    }
    return;
}

//엔진에 대한 모든 선택지 제공 추후 추가를 위해 car class에서 가져옴
void displayEngine() {
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < car.EngineLen; i++) {
        printf("%d, %s\n", i, car.engine_list[i]);
    }
    return;
}

//브레이크 시스템에 대한 모든 선택지 제공 추후 추가를 위해 car class에서 가져옴
void displayBreakSystem() {
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < car.BreakSystemLen; i++) {
        printf("%d, %s\n", i, car.break_system_list[i]);
    }
    return;
}

//조향장치에 대한 모든 선택지 제공 추후 추가를 위해 car class에서 가져옴
void displaySteeringSystem() {
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    for (int i = 1; i < car.SteeringSystemLen; i++) {
        printf("%d, %s\n", i, car.steering_system_list[i]);
    }
    return;
}

//순차에 맞는 출력을 유저에게 제공
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

//Car 객체에 입력을 넣기전 순서에 따라 올바른 입력이 들어왔는지 확인
bool isValidInput(int answer) {
    if (step == CarType_Q && !(answer >= 1 && answer < car.CarTypeLen))
    {
        printf("ERROR :: 차량 타입은 1 ~ %d 범위만 선택 가능\n", car.CarTypeLen - 1);
        delay(800);
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer < car.EngineLen))
    {
        printf("ERROR :: 엔진은 1 ~ %d 범위만 선택 가능\n", car.EngineLen - 1);
        delay(800);
        return true;
    }

    if (step == BreakSystem_Q && !(answer >= 0 && answer < car.BreakSystemLen))
    {
        printf("ERROR :: 제동장치는 1 ~ %d 범위만 선택 가능\n", car.BreakSystemLen - 1);
        delay(800);
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer < car.SteeringSystemLen))
    {
        printf("ERROR :: 조향장치는 1 ~ %d 범위만 선택 가능\n", car.SteeringSystemLen - 1);
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

// 입/출력에 대한 순서 관리
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