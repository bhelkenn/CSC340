#include "budget_application.h"

int main() {
	BudgetApplication application;
	while (application.is_running()) {
		application.prompt_loop();
		application.testEnvelopeBox();
	}
	
	return 0;
}