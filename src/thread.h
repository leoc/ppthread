#ifndef _THREADS_THREAD_H
#define _THREADS_THREAD_H

#include <pthread.h>

/*! \brief A simple thread wrapper for \p pthread_t */
class Thread {
private:
  pthread_t thread_; /*!< \p pthread_t we want to build our wrapper around. */
  
  /*! \brief Enum to describe the status of the thread object */
  volatile enum {
    THREAD_STOPPED,     /*!< \p pthread_t has been initialized but not created yet or stopped. */
    THREAD_PENDING,     /*!< \p pthread_t is changing */
    THREAD_RUNNING,     /*!< \p pthread_t has been initialized and created. */
  } status_;
protected:
	/*! \brief 	The static entry point for our thread.
	 *					The pthread library is a C library. Therefore we need a static c-like function
	 *					that we can pass over to the \p pthread_create function.
	 *	\param 	void* pointer to the thread we want to start
	 */
  static void* entry(void* pthis);
  
  /*! \brief 	The real thread function.
   * 					Override this function for your thread.
   *	\return int status of your thread
   */
  virtual int run() = 0;
public:
	/*! \brief 	Simple constructor 
	 *					Initializes the \p pthread_t member.
	 */
  Thread();
  
  /*! \brief 	Simple destructor.
   *					Destroys the \p pthread_t member.
   */
  virtual ~Thread();

	/*! \brief 	The starting method.
	 *					Invoke this function to create the \p pthread_t member.
	 *	\return int the status of the \p pthread_create function
	 */
  int start();
  
  /*! \brief 	Joins the running \p pthread_t
   *					This will invoke the \p pthread_join function with the \p pthread_t member
   *					as argument.
   *	\return int the status of the \p pthread_join function
   */
  int join();
};

#endif

