
#include "model/Application.hpp"
#include "ui/text/Application.hpp"

int main(){
	model::Application app;
	ui::text::Application appView;
	app.attach(appView);
	app.run();
	return 0;
}
