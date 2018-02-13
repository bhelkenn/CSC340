#include "budget_application.h"

enum Selection {
	EXIT,
	SHOW_BUDGET,
	DEPOSIT,
	WITHDRAW
};

//constructor/destructor
BudgetApplication::BudgetApplication() {
	ifstream load_file;
	load_file >> budget;
}
BudgetApplication::~BudgetApplication() {
	ofstream store_file;
	store_file << budget;
}

void BudgetApplication::prompt_loop() {
	menu.show_menu();
	BudgetApplication::process_menu_selection();
}

bool BudgetApplication::is_running() {
	return menu.last_selection() != 0;
}

void BudgetApplication::process_menu_selection() {
	Selection selection = static_cast<Selection>(menu.prompt_for_selection());
	switch (selection) {
		case SHOW_BUDGET:
			cout << budget;
			break;
		case DEPOSIT:
			budget.account_deposit(collectAccountId(), collectAmount());
			break;
		case WITHDRAW:
			budget.account_withdrawal(collectAccountId(), collectAmount());
			break;
		case EXIT:
			break;
		default:
			cout << "Something went wrong in BudgetApplication::process_menu_selection()" << endl;
	}
}

//test drivers
void BudgetApplication::testTreeFunctions() {
	Tree<BudgetEnvelope> tree;
	
	BudgetEnvelope *be = new BudgetEnvelope[5];
	for (int loop_count = 0; loop_count < 5; loop_count++) {
		BudgetEnvelope tmp(
			loop_count + 101,
			"test" + to_string(loop_count + 1),
			0.25 * loop_count);
		be[loop_count] = tmp;
	}
	
	testTreeInsert(be, tree);
	testTreeFind(be, tree);
	testTreeTraverse(tree);
}
void BudgetApplication::testEnvelopeBox() {
	//testing first constructor
	EnvelopeBox *envelopeboxes = new EnvelopeBox(budget.getEnvelopes(), budget.getEnvelopeCount(), 4, 2016);
	//testing second constructor - doesn't work
	//EnvelopeBox envelopeboxesprime(envelopeboxes, 5, 2016);
	
	//testing deposit and withdraw, success and failure
	BudgetEnvelope tmp_be(123, "tmp", 0);
	Tree<BudgetEnvelope> tree = envelopeboxes->getEnvelopes();
	BudgetEnvelope *be = tree.find(tmp_be);
	cout << (*be);
	envelopeboxes->deposit(123, 50.00);
	cout << (*be);
	envelopeboxes->withdraw(123, 100.00);
	cout << (*be);
	envelopeboxes->withdraw(123, 25.00);
	cout << (*be);
	
	cout << "finished" << endl;
}

//helper functions
void testTreeInsert(BudgetEnvelope *be, Tree<BudgetEnvelope> &tree) {
	for (int loop_count = 0; loop_count < 5; loop_count++) {
		cout << "Tree size is: " << tree.size() << endl;
		cout << "Tree height is: " << tree.height() << endl;
		tree.insert(be[loop_count]);
		cout << "Inserted " << be[loop_count].getTitle() << " into tree!" << endl;
	}
}
void testTreeFind(BudgetEnvelope *be, Tree<BudgetEnvelope> &tree) {
	BudgetEnvelope *result = tree.find(be[0]);
	cout << "Found: " << result->getId() << " " << result->getTitle() << endl;
	BudgetEnvelope bad(110, "test6", 1.25);
	result = tree.find(bad);
	if (result == NULL)
		cout << "NOT FOUND" << endl;
	else
		cout << "Found: " << result->getId() << " " << result->getTitle() << endl;
}
void testTreeTraverse(Tree<BudgetEnvelope> &tree) {
	cout << "***PREORDER TRAVERSAL***" << endl;
	tree.preorder_traversal();
	cout << "***INORDER TRAVERSAL***" << endl;
	tree.inorder_traversal();
	cout << "***POSTORDER TRAVERSAL***" << endl;
	tree.postorder_traversal();
}
double userInput() {
	double input = 0.0;
	cin >> input;
	return input;
}
int collectAccountId() {
	cout << "Enter an account ID: ";
	return static_cast<int>(userInput());
}
double collectAmount() {
	cout << "Enter an amount: ";
	return userInput();
}