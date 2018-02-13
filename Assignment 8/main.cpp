#include "budget_application.h"

int main() {
	BudgetApplication application;
	while (application.is_running()) {
		application.prompt_loop();
	}
	cout << "quitting" << endl;
	return 0;
}