#ifndef _THREADS_CONDITION_H
#define _THREADS_CONDITION_H

#include "mutex.h"

#include <pthread.h>

/*! \brief A simple condition wrapper around \p pthread_cond_t . */
class Condition : public Mutex {
protected:
  pthread_cond_t condition_; /*!< The \p pthread_cond_t we want to build our wrapper around */
public:
	/*! \brief 	Simple constructor.
	 *					Initializes the \p pthread_cond_t member with \p pthread_cond_init .
	 */
  Condition();
  
  /*! \brief 	Simple destructor.
   *					Destroys the \p pthread_cond_t member with \p pthread_cond_destroy .
   */
  virtual ~Condition();

	/*! \brief 	Waits for a signal.
	 *					Invokes the \p pthread_cond_wait function for the wrapped \p pthread_cond_t member.
	 *	\return int status of the \p pthread_cond_wait function
	 */
  int wait();
  
  /*! \brief 	Sends signals for waiting threads.
 	 *					Invokes the \p pthread_cond_signal function for the wrapped \p pthread_cond_t member.
 	 *	\return int status of the \p pthread_cond_signal function
 	 */
  int signal();
};

#endif
