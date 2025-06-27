#pragma once
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>

class Car
{
private:
    int car_type, engine, break_system, steering_system;

public:
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
        BrokenEngine,

        EngineLen
    };

    enum BreakSystem
    {
        Mando = 1,
        Continental,
        BoschB,
        BreakSystemLen
    };

    enum SteeringSystem
    {
        BoschS = 1,
        Mobis,

        SteeringSystemLen
    };

    std::string car_type_list[10] = { "", "Sedan", "SUV", "Truck" };
    std::string engine_list[10] = { "", "GM", "TOYOTA", "WIA", "고장난 엔진" };
    std::string break_system_list[10] = { "", "MANDO", "CONTINENTAL", "BOSCH_B" };
    std::string steering_system_list[10] = { "", "BOSCH_S", "MOBIS" };

    Car();
    void SetCarType(int num);
    void SetEngine(int num);
    void SetBreakSystem(int num);
    void SetSteeringSystem(int num);
    int GetCarType();
    int GetEngine();
    int GetBreakSystem();
    int GetSteeringSystem();
    std::string GetCarTypeString();
    std::string GetEngineString();
    std::string GetBreakSystemString();
    std::string GetSteeringSystemString();
    bool CarSelfTest();

    bool SedanBreakCheck();
    bool SuvEngineCheck();
    bool TruckEngineCheck();
    bool TruckBreakCheck();
    bool BoschSetCheck();
};

