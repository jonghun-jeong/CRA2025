#pragma once
#include "Car.h"
    // 기본 item을 0으로 세팅하는 생성자
    Car::Car() {
        car_type = 0;
        engine = 0;
        break_system = 0;
        steering_system = 0;
    }
    // 디자인 패턴에 맞춰 캡슐화된 API로만 item 접근 가능
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

    // 자체 검증 API를 활용한 차량의 적합 여부 판단
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

    //제약 사항에 만족 여부를 확인하기 위한 자체 검증 API
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

    
