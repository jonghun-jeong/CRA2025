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
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        int answer;
        try {
            answer = std::stoi(context);
        }
        catch (std::invalid_argument&) {
            // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
            printf("ERROR :: ���ڸ� �Է� ����\n");
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
    printf("���� Ÿ������ %s��(��) �����ϼ̽��ϴ�.\n",  car.GetCarTypeString());
}

void selectEngine(int answer)
{
    car.SetEngine(answer);
    printf("%s ������ �����ϼ̽��ϴ�.\n", car.GetEngineString());
}

void selectBreakSystem(int answer)
{
    car.SetBreakSystem(answer);
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", car.GetBreakSystemString());
}

void selectSteeringSystem(int answer)
{
    car.SetSteeringSystem(answer);
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", car.GetSteeringSystemString());
}

//�ڵ����� ���� ���� Ȯ��
void runProducedCar()
{
    if (car.CarSelfTest() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (car.GetEngine() == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            printf("Car Type : %s\n", car.GetCarTypeString());
            printf("Engine : %s\n", car.GetEngineString());
            printf("Break System : %s\n", car.GetBreakSystemString());
            printf("SteeringSystem : %s\n", car.GetSteeringSystemString());

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

//�ڵ��� ���� �� ���� �׽�Ʈ
void testProducedCar()
{
    if (car.SedanBreakCheck())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (car.SuvEngineCheck())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (car.TruckEngineCheck())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (car.TruckBreakCheck())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (car.BoschSetCheck())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
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

//�ڵ��� Ÿ�Կ� ���� ��� ������ ���� ���� �߰��� ���� car class���� ������
void displayCarType() {
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("� ���� Ÿ���� �����ұ��?\n");

    for (int i = 1; i < car.CarTypeLen; i++) {
        printf("%d, %s\n", i, car.car_type_list[i]);
    }
    return;
}

//������ ���� ��� ������ ���� ���� �߰��� ���� car class���� ������
void displayEngine() {
    printf(CLEAR_SCREEN);
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    for (int i = 1; i < car.EngineLen; i++) {
        printf("%d, %s\n", i, car.engine_list[i]);
    }
    return;
}

//�극��ũ �ý��ۿ� ���� ��� ������ ���� ���� �߰��� ���� car class���� ������
void displayBreakSystem() {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    for (int i = 1; i < car.BreakSystemLen; i++) {
        printf("%d, %s\n", i, car.break_system_list[i]);
    }
    return;
}

//������ġ�� ���� ��� ������ ���� ���� �߰��� ���� car class���� ������
void displaySteeringSystem() {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    for (int i = 1; i < car.SteeringSystemLen; i++) {
        printf("%d, %s\n", i, car.steering_system_list[i]);
    }
    return;
}

//������ �´� ����� �������� ����
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
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");

    std::getline(std::cin, buf);

    // ���� ���๮�� ����
    std::istringstream iss(buf);
    iss >> context;

}

//Car ��ü�� �Է��� �ֱ��� ������ ���� �ùٸ� �Է��� ���Դ��� Ȯ��
bool isValidInput(int answer) {
    if (step == CarType_Q && !(answer >= 1 && answer < car.CarTypeLen))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ %d ������ ���� ����\n", car.CarTypeLen - 1);
        delay(800);
        return true;
    }

    if (step == Engine_Q && !(answer >= 0 && answer < car.EngineLen))
    {
        printf("ERROR :: ������ 1 ~ %d ������ ���� ����\n", car.EngineLen - 1);
        delay(800);
        return true;
    }

    if (step == BreakSystem_Q && !(answer >= 0 && answer < car.BreakSystemLen))
    {
        printf("ERROR :: ������ġ�� 1 ~ %d ������ ���� ����\n", car.BreakSystemLen - 1);
        delay(800);
        return true;
    }

    if (step == SteeringSystem_Q && !(answer >= 0 && answer < car.SteeringSystemLen))
    {
        printf("ERROR :: ������ġ�� 1 ~ %d ������ ���� ����\n", car.SteeringSystemLen - 1);
        delay(800);
        return true;
    }

    if (step == RunTest_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(800);
        return true;
    }
    return false;
}

// ��/��¿� ���� ���� ����
bool flowControl(int answer) {
    // ó������ ���ư���
    if (answer == 0 && step == RunTest_Q)
    {
        step = CarType_Q;
        return true;
    }

    // �������� ���ư���
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