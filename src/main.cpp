
#include "model/Application.hpp"
#include "ui/text/Application.hpp"

int main(){
	model::Application app;
	ui::text::Application appView;
	app.sigModified.connect(
		[&appView](model::Application const & app){appView.notify(app);}
	);
	app.run();
	return 0;
}
