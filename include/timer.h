#ifndef __TIMER_H__
#define __TIMER_H__

//The timer
class Timer {
    private:
    //The clock time when the timer started
    unsigned int startTicks;

    //The ticks stored when the timer was paused
    unsigned int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    unsigned int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

#endif
