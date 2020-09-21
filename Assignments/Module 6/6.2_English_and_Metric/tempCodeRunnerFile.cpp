
                    centimeters = inches * 2.54; 
                    cout << inches << " inches is equal to " << centimeters << " centimeters." << endl;
                }
            } else if (selection == 'M') {
                // user wants to convert from Metric to English
                cout << endl << "Enter the number of centimeters: "; 
                cin >> centimeters; 

                if (cin.fail()) {
                    throw 0; 