/*!	\file mutex.h
 * 	\brief A simple mutex wrapper for \p pthread_mutex_t.
 */

#ifndef _THREADS_MUTEX_H
#define _THREADS_MUTEX_H

#include <pthread.h>

/*! \brief A simple mutex wrapper for \p pthread_mutex_t. */
class Mutex {
protected:
  pthread_mutex_t mutex_; /*!< The pthread_mutex_t we want to build our wrapper around */ 
public:
	/*! \brief 	Simple constructor.
	 *					Initializes the \p pthread_mutex_t with \p pthread_mutex_init().
	 */
  Mutex();
  /*! \brief 	Simple destructor.
	 *					Destroys the \p pthread_mutex_t with \p pthread_mutex_destroy().
	 */
  ~Mutex();
	
	/*! \brief 	Locks the mutex.
	 *					Invokes \p pthread_mutex_lock function for the wrapped \p pthread_mutex_t member.
	 *	\return int status of the \p pthread_mutex_lock function
	 */
  int lock();
  
  /*! \brief 	Unlocks the mutex.
   *					Invokes \p pthread_mutex_unlock function for the wrapped \p pthread_mutex_t member.
   *	\return int status of the \p pthread_mutex_unlock function
   */
  int unlock();
  
  /*! \brief 	Tries to lock the mutex.
   *					Invokes the \p pthread_mutex_trylock function for the wrapped \p pthread_mutex_t member.
   *	\return int status of the \p pthread_mutex_trylock function
   */
  int trylock();
};

#endif

