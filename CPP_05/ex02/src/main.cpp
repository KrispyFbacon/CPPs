#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

std::string intToString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

void test1_validFormCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 1: Valid Form Creation           ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	try
	{
		Bureaucrat bacon("Bacon", 1);
		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Garden");
		PresidentialPardonForm pres("Council");
		
		std::cout << bacon << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pres << std::endl;
		std::cout << std::endl;

		bacon.signForm(shrub);
		bacon.signForm(robot);
		bacon.signForm(pres);
		std::cout << std::endl;

		bacon.executeForm(shrub);
		bacon.executeForm(robot);
		bacon.executeForm(pres);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test2_executeUnsignedForm()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 2: Execute Unsigned Form         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("Garden");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		std::cout << std::endl;
		
		std::cout << "Attempting to execute unsigned form..." << std::endl;
		bob.executeForm(shrub);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test3_gradeTooLowToSign()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 3: Grade Too Low to Sign         ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat lowly("Lowly", 150);
		PresidentialPardonForm pres("Criminal");
		
		std::cout << lowly << std::endl;
		std::cout << pres << std::endl;
		std::cout << std::endl;
		
		std::cout << "Attempting to sign Presidential Pardon (requires grade 25)..." << std::endl;
		lowly.signForm(pres);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test4_gradeTooLowToExecute()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 4: Grade Too Low to Execute      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat signer("Signer", 20);
		Bureaucrat executor("Executor", 100);
		PresidentialPardonForm pres("Prisoner");
		
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << pres << std::endl;
		std::cout << std::endl;
		
		signer.signForm(pres);
		std::cout << std::endl;
		
		std::cout << "Attempting to execute with grade 100 (requires grade 5)..." << std::endl;
		executor.executeForm(pres);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test5_robotomyRandomness()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 5: Robotomy Randomness (50%)     ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat master("Master", 1);
		
		std::cout << "Attempting 5 robotomies to test randomness:" << std::endl;
		std::cout << std::endl;
		
		for (int i = 1; i <= 5; i++)
		{
			std::stringstream ss;
			ss << "Target" << i;
			std::string target = ss.str();
			
			RobotomyRequestForm robot(target);
			
			master.signForm(robot);
			master.executeForm(robot);
			std::cout << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test6_multipleShrubberyCreation()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 6: Multiple Shrubbery Files      ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat gardener("Gardener", 100);
		ShrubberyCreationForm shrub1("Backyard");
		ShrubberyCreationForm shrub2("Frontyard");
		ShrubberyCreationForm shrub3("Park");
		
		std::cout << gardener << std::endl;
		std::cout << std::endl;
		
		gardener.signForm(shrub1);
		gardener.signForm(shrub2);
		gardener.signForm(shrub3);
		std::cout << std::endl;
		
		gardener.executeForm(shrub1);
		gardener.executeForm(shrub2);
		gardener.executeForm(shrub3);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test7_borderlineGrades()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 7: Borderline Grades             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat shrubSigner("ShrubSigner", 145);
		Bureaucrat shrubExecutor("ShrubExecutor", 137);
		ShrubberyCreationForm shrub("Border");
		
		std::cout << "Testing with exact required grades (145 to sign, 137 to execute):" << std::endl;
		std::cout << shrubSigner << std::endl;
		std::cout << shrubExecutor << std::endl;
		std::cout << shrub << std::endl;
		std::cout << std::endl;
		
		shrubSigner.signForm(shrub);
		shrubExecutor.executeForm(shrub);
		
		std::cout << std::endl;
		
		Bureaucrat tooLow("TooLow", 146);
		ShrubberyCreationForm shrub2("TooLow");
		
		std::cout << "Testing with grade 146 (one too low to sign):" << std::endl;
		std::cout << tooLow << std::endl;
		std::cout << std::endl;
		
		tooLow.signForm(shrub2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test8_copyAndAssignment()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 8: Copy & Assignment             ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm original("Original");
		
		std::cout << "Original form:" << std::endl;
		std::cout << original << std::endl;
		std::cout << std::endl;
		
		ShrubberyCreationForm copy(original);
		std::cout << "Copied form:" << std::endl;
		std::cout << copy << std::endl;
		std::cout << std::endl;
		
		ShrubberyCreationForm assigned("WillBeReplaced");
		assigned = original;
		std::cout << "Assigned form:" << std::endl;
		std::cout << assigned << std::endl;
		std::cout << std::endl;
		
		boss.signForm(copy);
		boss.executeForm(copy);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test9_polymorphismWithPointers()
{
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║  Test 9: Polymorphism (with new)       ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	AForm* shrub = NULL;
	AForm* robot = NULL;
	AForm* pres = NULL;
	
	try
	{
		Bureaucrat boss("Boss", 1);
		
		shrub = new ShrubberyCreationForm("Polymorphic");
		robot = new RobotomyRequestForm("R2D2");
		pres = new PresidentialPardonForm("Convict");
		
		std::cout << boss << std::endl;
		std::cout << *shrub << std::endl;
		std::cout << *robot << std::endl;
		std::cout << *pres << std::endl;
		std::cout << std::endl;
		
		boss.signForm(*shrub);
		boss.signForm(*robot);
		boss.signForm(*pres);
		std::cout << std::endl;
		
		boss.executeForm(*shrub);
		boss.executeForm(*robot);
		boss.executeForm(*pres);
		
		delete shrub;
		delete robot;
		delete pres;
	}
	catch (const std::exception& e)
	{
		delete shrub;
		delete robot;
		delete pres;
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	
	test1_validFormCreation();
	test2_executeUnsignedForm();
	test3_gradeTooLowToSign();
	test4_gradeTooLowToExecute();
	test5_robotomyRandomness();
	test6_multipleShrubberyCreation();
	test7_borderlineGrades();
	test8_copyAndAssignment();
	test9_polymorphismWithPointers();
	
	std::cout << BOLD_C << "\n╔════════════════════════════════════════╗" << RST << std::endl;
	std::cout << BOLD_C << "║         All Tests Completed            ║" << RST << std::endl;
	std::cout << BOLD_C << "╚════════════════════════════════════════╝" << RST << std::endl;
	
	return 0;
}