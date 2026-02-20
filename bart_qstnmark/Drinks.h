#pragma once
class Drinks
{
protected:
	int id; // ID напітку, який буде використовуватися для мініігри
public:
	virtual ~Drinks() = default; // віртуальний деструктор для правильного видалення об'єктів похідних класів
	virtual int getID() const = 0; // чисто віртуальна функція для отримання ID напітку
};

												