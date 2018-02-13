#include "Envelope.h"
#include "Budget.h"
#include "Account.h"
#include "budget_application.h"

int main() {
	BudgetApplication application;
	while (application.is_running()) {
		application.prompt_loop();
	}
	
	return 0;
}