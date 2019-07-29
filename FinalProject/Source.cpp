#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MassageBox.h"
#include "../Common/RadioList.h"
#include "../Common/RadioBox.h"
#include "../Common/ComboBox.h"
#include <iostream>

int main(int argc, char **argv)
{
	EventEngine engine;
	Panel panel(new NormalBorder(), 1, 1);
	panel.setWidth(100);
	panel.setHeight(30);

	Label headerLabel(42, 1, "Pizza Order");
	Label toppingsLabel(5, 3, "Toppings");
	CheckList toppingChecklist(new DblBorder(), 3, 4, {"Olives", "Paparoni", "Extra cheese"});
	Label paymentLabel(5, 15, "Payment");
	RadioList paymentRadioList(new DblBorder(), 3, 16, {"Credit Card", "Cash", "Coupon"});
	Label nameLabel(35, 3, "Name");
	TextBox nameTextBox(new NormalBorder(), 35, 5, 20, 4);
	Label phoneLabel(35, 8, "Phone number");
	TextBox phoneTextBox(new NormalBorder(), 35, 10, 20, 4);
	Label numOfPizzaLabel(35, 14, "Number of pizzas");
	NumericBox numbox(new NormalBorder(), 35, 16);
	Label drinksLabel(35, 19, "Choose drink");
	ComboBox combo(new NormalBorder(), 35, 21, {"CocaCola", "Sprite", "Fanta"});

	Button orderBtn(new DblBorder(), 70, 10, "ORDER NOW!");
	PopUp popup(62, 15, "Confirm order");

	orderBtn.setEvent(&popup);
	panel.add(&nameTextBox);
	panel.add(&phoneTextBox);
	panel.add(&numbox);
	panel.add(&combo);
	panel.add(&orderBtn);
	panel.add(&headerLabel);
	panel.add(&toppingsLabel);
	panel.add(&paymentLabel);
	panel.add(&nameLabel);
	panel.add(&phoneLabel);
	panel.add(&numOfPizzaLabel);
	panel.add(&drinksLabel);
	panel.add(&popup);
	panel.add(&toppingChecklist);
	panel.add(&paymentRadioList);
	Control *firstFocus;
	if (firstFocus = panel.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	engine.run(panel);
}