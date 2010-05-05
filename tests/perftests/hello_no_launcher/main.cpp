/*
 * An example of a minimalistic DirectUI application
 */

#include <MApplication>
#include <MApplicationWindow>
#include <MApplicationPage>
#include <MButton>

int main(int argc, char** argv)
{
    /* The base class of all DirectUI applications */
    MApplication app(argc, argv);

    /* The application window is a top-level window that contains
       the Home and Back/Close framework controls, Navigation bar,
       View menu and Toolbar components */
    MApplicationWindow w;
    w.show();

    /* Pages represent one "view" of an application, into which you
       can add your application's contents. An application can have
       any number of pages with transitions between them */
    MApplicationPage p;

    /* Let's add a simple push button to our page */
    MButton b(p.centralWidget()); /* The (optional) constructor parameter
                                       causes our button to be a child of the
                                       central widget of the page. This
                                       pattern can be used with all MWidgets
                                    */
    b.setText("Hello World!");

    p.appear(); /* appearNow causes the page to be visible without
                   a transition animation, which is recommended
                   for the initial application page */

    return app.exec();
}