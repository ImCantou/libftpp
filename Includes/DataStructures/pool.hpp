#ifndef __POOL_CLASS__
#define __POOL_CLASS__

# include <deque>
# include <iostream>

template <typename TType>
class Pool {
	
	public:
		class Object {
			private:
				TType* ptr = NULL;

			public:
				Object(TType arg): ptr(&arg) {};
				~Object() {};

				TType* operator -> () {
					return ptr;
				}
		};

		template<typename ... TArgs>
		Object acquire(TArgs&&... p_args) {
			std::cout << "Acquiring Pool Object" << std::endl << std::endl;

			Object ret(Objects.front());
			Objects.pop_front();
			return (ret);
		};

		void resize(const size_t& numberOfObjectsStored) {
			std::cout << "Resizing Pool with a size of " << numberOfObjectsStored << std::endl << std::endl;
			Objects.resize(numberOfObjectsStored);
		};

		Pool() {
			std::cout << "Creating Pool" << std::endl << std::endl;
		};



	private:
		std::deque<TType>	Objects;
		std::deque<TType *> ObjectsPtr;
		size_t				size = 0;
		
};




#endif