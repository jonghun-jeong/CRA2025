#pragma once
#include "Car.h"
    // �⺻ item�� 0���� �����ϴ� ������
    Car::Car() {
        car_type = 0;
        engine = 0;
        break_system = 0;
        steering_system = 0;
    }
    // ������ ���Ͽ� ���� ĸ��ȭ�� API�θ� item ���� ����
    void Car::SetCarType(int num) {
        car_type = num;
    }
    void Car::SetEngine(int num) {
        engine = num;
    }
    void Car::SetBreakSystem(int num) {
        break_system = num;
    }
    void Car::SetSteeringSystem(int num) {
        steering_system = num;
    }
    int Car::GetCarType() {
        return car_type;
    }
    int Car::GetEngine() {
        return engine;
    }
    int Car::GetBreakSystem() {
        return break_system;
    }
    int Car::GetSteeringSystem() {
        return steering_system;
    }
    std::string Car::GetCarTypeString() {
        return car_type_list[car_type];
    }
    std::string Car::GetEngineString() {
        return engine_list[engine];
    }
    std::string Car::GetBreakSystemString() {
        return break_system_list[break_system];
    }
    std::string Car::GetSteeringSystemString() {
        return steering_system_list[steering_system];
    }

    // ��ü ���� API�� Ȱ���� ������ ���� ���� �Ǵ�
    bool Car::CarSelfTest() {
        if (SedanBreakCheck())
        {
            return false;
        }
        if (SuvEngineCheck())
        {
            return false;
        }
        if (TruckEngineCheck())
        {
            return false;
        }
        if (TruckBreakCheck())
        {
            return false;
        }
        if (BoschSetCheck())
        {
            return false;
        }
        return true;
    }

    //���� ���׿� ���� ���θ� Ȯ���ϱ� ���� ��ü ���� API
    bool Car::SedanBreakCheck() {
        return car_type == Sedan && break_system == Continental;
    }
    bool Car::SuvEngineCheck() {
        return car_type == SUV && engine == Toyota;
    }
    bool Car::TruckEngineCheck() {
        return car_type == Truck && engine == WIA;
    }
    bool Car::TruckBreakCheck() {
        return car_type == Truck && break_system == Mando;
    }
    bool Car::BoschSetCheck() {
        return break_system == BoschB && steering_system != BoschS;
    }

    
