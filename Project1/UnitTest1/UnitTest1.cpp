#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\Character.h"
#include "..\Project1\MagicCharacter.h"
#include "..\Project1\Weapon.h"
#include "..\Project1\HealingStick.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodCharacterAttackHitsWithNoWeapon)
		{
			// arrange
			Character attacker("", 1, 0, 0, 0);
			Character* target = new Character("", 1, 1, 1, 0);
			int expectedHitPoints = 0;

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestMethodCharacterDoesntAttackWith0HitPoints)
		{
			// arrange
			Character attacker("", 0, 0, 0, 0);
			Character* target = new Character("", 1, 1, 1, 0);
			int expectedHitPoints = 1;

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestMethodCharacterDoesntHitWhenNotInRange)
		{
			// arrange
			Character attacker("", 0, 0, 0, 0);
			Character* target = new Character("", 1, 2, 2, 0);
			int expectedHitPoints = 1;

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestMethodCharacterAttackHitsWithWeapon)
		{
			// arrange
			int startingHitPoints = 20;
			Weapon* weapon = new Weapon("", 10, 10);
			Character attacker("", 1, 0, 0, 0, weapon);
			Character* target = new Character("", startingHitPoints, 1, 1, 0);

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::IsTrue(actualHitPoints < startingHitPoints);

		}

		TEST_METHOD(TestMethodMagicCharacterHits)
		{
			// arrange
			MagicCharcter attacker("", 1, 0, 0, 0, 10);
			Character* target = new Character("", 10, 1, 1, 0);
			int expectedHitPoints = 7;

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestMethodCharacterHealingStickHeals)
		{
			// arrange
			int startingHitPoints = 20;
			Weapon* weapon = new HealingStick("", 10, 10);
			Character attacker("", 1, 0, 0, 0, weapon);
			Character* target = new Character("", startingHitPoints, 1, 1, 0);
			target->takeDamage(startingHitPoints);

			// act
			attacker.attack(*target);
			int actualHitPoints = target->getCurrentHitPoints();

			// assert
			Assert::IsTrue(actualHitPoints > 0);

		}
	};
}
