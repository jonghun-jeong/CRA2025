#include "gmock/gmock.h"
#include "Car.h"
#include "gtest/gtest.h"

TEST(ItemValue, CarType) {
	Car car;
	for (int i = 1; i < car.CarTypeLen; i++) {
		car.SetCarType(i);
		EXPECT_EQ(car.GetCarType(), i);
	}
}

TEST(ItemValue, Engine) {
	Car car;
	for (int i = 1; i < car.EngineLen; i++) {
		car.SetEngine(i);
		EXPECT_EQ(car.GetEngine(), i);
	}

}

TEST(ItemValue, BreakSystem) {
	Car car;
	for (int i = 1; i < car.BreakSystemLen; i++) {
		car.SetBreakSystem(i);
		EXPECT_EQ(car.GetBreakSystem(), i);
	}
}

TEST(ItemValue, SteeringSystem) {
	Car car;
	for (int i = 1; i < car.SteeringSystemLen; i++) {
		car.SetSteeringSystem(i);
		EXPECT_EQ(car.GetSteeringSystem(), i);
	}
}

TEST(ItemString, CarTypeString) {
	std::string car_type_list[10] = { "", "Sedan", "SUV", "Truck" };
	Car car;
	for (int i = 1; i < car.CarTypeLen; i++) {
		car.SetCarType(i);
		EXPECT_THAT(car.GetCarTypeString(), car_type_list[i]);
	}
}

TEST(ItemString, EngineString) {
	std::string engine_list[10] = { "", "GM", "TOYOTA", "WIA", "고장난 엔진" };
	Car car;
	for (int i = 1; i < car.EngineLen; i++) {
		car.SetEngine(i);
		EXPECT_THAT(car.GetEngineString(), engine_list[i]);
	}

}

TEST(ItemString, BreakSystemString) {
	std::string break_system_list[10] = { "", "MANDO", "CONTINENTAL", "BOSCH_B" };
	Car car;
	for (int i = 1; i < car.BreakSystemLen; i++) {
		car.SetBreakSystem(i);
		EXPECT_THAT(car.GetBreakSystemString(), break_system_list[i]);
	}
}

TEST(ItemString, SteeringSystemString) {
	std::string steering_system_list[10] = { "", "BOSCH_S", "MOBIS" };
	Car car;
	for (int i = 1; i < car.SteeringSystemLen; i++) {
		car.SetSteeringSystem(i);
		EXPECT_THAT(car.GetSteeringSystemString(), steering_system_list[i]);
	}
}

TEST(FeatureTest, SelfTest1) {
	Car car;
	car.SetCarType(car.Sedan);
	car.SetBreakSystem(car.Continental);
	
	car.SetSteeringSystem(car.BoschS);
	car.SetEngine(car.GM);
	EXPECT_FALSE(car.CarSelfTest());
}

TEST(FeatureTest, SelfTest2) {
	Car car;
	car.SetCarType(car.SUV);
	car.SetEngine(car.Toyota);

	car.SetSteeringSystem(car.BoschS);
	car.SetBreakSystem(car.Mando);
	EXPECT_FALSE(car.CarSelfTest());
}

TEST(FeatureTest, SelfTest3) {
	Car car;
	car.SetCarType(car.Truck);
	car.SetEngine(car.WIA);

	car.SetSteeringSystem(car.BoschS);
	car.SetBreakSystem(car.Continental);
	EXPECT_FALSE(car.CarSelfTest());
}

TEST(FeatureTest, SelfTest4) {
	Car car;
	car.SetCarType(car.Truck);
	car.SetBreakSystem(car.Mando);

	car.SetSteeringSystem(car.BoschS);
	car.SetEngine(car.GM);
	EXPECT_FALSE(car.CarSelfTest());
}

TEST(FeatureTest, SelfTest5) {
	Car car;
	std::string steering_system_list[10] = { "", "BOSCH_S", "MOBIS" };
	
	car.SetCarType(car.Truck);
	car.SetEngine(car.GM);

	car.SetBreakSystem(car.BoschB);
	for (int i = 2; i < car.SteeringSystemLen; i++) {
		car.SetSteeringSystem(i);
		EXPECT_FALSE(car.CarSelfTest());
	}
	
}

TEST(FeatureTest, SedanBreak) {
	Car car;
	car.SetCarType(car.Sedan);
	car.SetBreakSystem(car.Continental);
	EXPECT_TRUE(car.SedanBreakCheck());
}

TEST(FeatureTest, SuvEngine) {
	Car car;
	car.SetCarType(car.SUV);
	car.SetEngine(car.Toyota);
	EXPECT_TRUE(car.SuvEngineCheck());
}

TEST(FeatureTest, TruckEngine) {
	Car car;
	car.SetCarType(car.Truck);
	car.SetEngine(car.WIA);
	EXPECT_TRUE(car.TruckEngineCheck());
}

TEST(FeatureTest, TruckBreak) {
	Car car;
	car.SetCarType(car.Truck);
	car.SetBreakSystem(car.Mando);
	EXPECT_TRUE(car.TruckBreakCheck());
}

TEST(FeatureTest, BoschSet) {
	Car car;
	std::string steering_system_list[10] = { "", "BOSCH_S", "MOBIS" };

	car.SetBreakSystem(car.BoschB);
	for (int i = 2; i < car.SteeringSystemLen; i++) {
		car.SetSteeringSystem(i);
		EXPECT_TRUE(car.BoschSetCheck());
	}

}

TEST(ResultCheck, HappyPath) {
	Car car;
	car.SetCarType(car.Sedan);
	car.SetEngine(car.Toyota);

	car.SetSteeringSystem(car.BoschS);
	car.SetBreakSystem(car.Mando);
	EXPECT_TRUE(car.CarSelfTest());
}