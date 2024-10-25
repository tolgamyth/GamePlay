#include "pch.h"

#include "framework/Base.h"
#include "math/MathUtil.h"

using namespace gameplay;

class TestMathUtil : public ::testing::Test {
protected:
  void SetUp() override {
  }

  void TearDown() override {
  }
};

// Test when elapsedTime is greater than zero
TEST_F(TestMathUtil, SmoothWithPositiveElapsedTime) {
  float x = 0.0f;
  float target = 10.0f;
  float elapsedTime = 1.0f;
  float responseTime = 1.0f;

  MathUtil::smooth(&x, target, elapsedTime, responseTime);

  // Expect the value to be adjusted towards the target
  EXPECT_NEAR(x, 5.0f, 0.01f); // Using NEAR for floating-point comparison
}

// Test when elapsedTime is zero
TEST_F(TestMathUtil, SmoothWithZeroElapsedTime) {
  float x = 0.0f;
  float target = 10.0f;
  float elapsedTime = 0.0f;
  float responseTime = 1.0f;

  MathUtil::smooth(&x, target, elapsedTime, responseTime);

  // Expect the value to remain unchanged
  EXPECT_FLOAT_EQ(x, 0.0f); // x should remain 0.0
}

// Test when responseTime is zero
TEST_F(TestMathUtil, SmoothWithZeroResponseTime) {
  float x = 0.0f;
  float target = 10.0f;
  float elapsedTime = 1.0f;
  float responseTime = 0.0f;

  MathUtil::smooth(&x, target, elapsedTime, responseTime);

  // Expect x to be adjusted towards target
  EXPECT_NEAR(x, 10.0f, 0.01f); // Directly jumps to target
}
#ifdef _DEBUG

// Test when reference is nullptr
TEST_F(TestMathUtil, SmoothWithNullPointer) {

  ASSERT_DEATH(gameplay::MathUtil::smooth(nullptr, 0.006f, 0.005f, 0.1f), "");
}

#endif // _DEBUG
