# Suggested Makefile for CSE_1325 Homework #6 full_credit
CXXFLAGS += --std=c++17 
GTKFLAGS += `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mavmart

debug: CXXFLAGS += -g
debug: all

test: CXXFLAGS += -g
test: test_product test_product_order test_order test_store

mavmart: main.o dialogs.o controller.o  view.o store.o order.o product.o product_order.o *.h
	${CXX} ${CXXFLAGS} -o mavmart main.o dialogs.o controller.o view.o store.o order.o product.o product_order.o ${GTKFLAGS}
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp ${GTKFLAGS}
controller.o: controller.cpp *.h
	${CXX} ${CXXFLAGS} -c controller.cpp ${GTKFLAGS}
view.o: view.cpp *.h
	${CXX} ${CXXFLAGS} -c view.cpp ${GTKFLAGS}
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp ${GTKFLAGS}
order.o: order.cpp *.h
	${CXX} ${CXXFLAGS} -c order.cpp ${GTKFLAGS}
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp ${GTKFLAGS}
product_order.o: product_order.cpp *.h 
	${CXX} ${CXXFLAGS} -c product_order.cpp ${GTKFLAGS}

test_product: test_product.o product.o *.h
	${CXX} ${CXXFLAGS} -o test_product test_product.o product.o ${GTKFLAGS}
	-./test_product
test_product.o: test_product.cpp *.h
	${CXX} ${CXXFLAGS} -c test_product.cpp ${GTKFLAGS}

test_product_order: test_product_order.o product_order.o product.o *.h
	${CXX} ${CXXFLAGS} -o test_product_order test_product_order.o product_order.o product.o ${GTKFLAGS}
	-./test_product_order
test_product_order.o: test_product_order.cpp *.h
	${CXX} ${CXXFLAGS} -c test_product_order.cpp ${GTKFLAGS}

test_order: test_order.o order.o product_order.o product.o *.h
	${CXX} ${CXXFLAGS} -o test_order test_order.o order.o product_order.o product.o ${GTKFLAGS}
	-./test_order
test_order.o: test_order.cpp *.h
	${CXX} ${CXXFLAGS} -c test_order.cpp ${GTKFLAGS}

test_store: test_store.o store.o order.o product_order.o product.o *.h
	${CXX} ${CXXFLAGS} -o test_store test_store.o store.o order.o product_order.o product.o ${GTKFLAGS}
	-./test_store
test_store.o: test_store.cpp *.h
	${CXX} ${CXXFLAGS} -c test_store.cpp ${GTKFLAGS}

dialogs.o: dialogs.cpp *.h
	${CXX} ${CXXFLAGS} -c dialogs.cpp ${GTKFLAGS}

clean:
	-rm -f *.gch *.o *~ a.out mavmart test_product test_product_order test_order test_store
