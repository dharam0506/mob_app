// Run this in terminal below command
// flutter pub add provider
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

void main() {
  runApp(
    ChangeNotifierProvider(
      create: (context) => UserData(),
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'User Info',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const HomeScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class UserData extends ChangeNotifier {
  String name = '';
  String id = '';
  String gender = '';
  List<String> hobbies = [];

  void updateUserData(
      String newName, String newId, String newGender, List<String> newHobbies) {
    name = newName;
    id = newId;
    gender = newGender;
    hobbies = newHobbies;
    notifyListeners();
  }
}

class HomeScreen extends StatefulWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final TextEditingController nameController = TextEditingController();
  final TextEditingController idController = TextEditingController();

  String genderValue = "";
  bool hobby1 = false;
  bool hobby2 = false;
  bool hobby3 = false;

  final GlobalKey<FormState> formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("User Info"),
      ),
      body: Form(
        key: formKey,
        child: Column(
          children: [
            const SizedBox(height: 10),
            TextFormField(
              controller: nameController,
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Please Enter Your Name';
                }
                return null;
              },
              decoration: InputDecoration(
                labelText: "Enter Your Name",
                border: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(15),
                ),
              ),
            ),
            const SizedBox(height: 10),
            TextFormField(
              controller: idController,
              validator: (value) {
                if (value!.isEmpty) {
                  return 'Please Enter your ID';
                }
                return null;
              },
              decoration: InputDecoration(
                labelText: "Enter your ID",
                border: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(15),
                ),
              ),
            ),
            const SizedBox(height: 10),
            RadioListTile(
              value: 'Male',
              groupValue: genderValue,
              onChanged: (val) {
                setState(() {
                  genderValue = val.toString();
                });
              },
              title: const Text("Male"),
            ),
            RadioListTile(
              value: 'Female',
              groupValue: genderValue,
              onChanged: (val) {
                setState(() {
                  genderValue = val.toString();
                });
              },
              title: const Text("Female"),
            ),
            CheckboxListTile(
              value: hobby1,
              onChanged: (value) {
                setState(() {
                  hobby1 = !hobby1;
                });
              },
              title: const Text("Playing"),
            ),
            CheckboxListTile(
              value: hobby2,
              onChanged: (value) {
                setState(() {
                  hobby2 = !hobby2;
                });
              },
              title: const Text("Singing"),
            ),
            CheckboxListTile(
              value: hobby3,
              onChanged: (value) {
                setState(() {
                  hobby3 = !hobby3;
                });
              },
              title: const Text("Drawing"),
            ),
            ElevatedButton(
              onPressed: () {
                if (formKey.currentState!.validate()) {
                  List<String> selectedHobbies = [];
                  if (hobby1) selectedHobbies.add('Playing');
                  if (hobby2) selectedHobbies.add('Singing');
                  if (hobby3) selectedHobbies.add('Drawing');

                  // Update user data in provider
                  Provider.of<UserData>(context, listen: false).updateUserData(
                    nameController.text,
                    idController.text,
                    genderValue,
                    selectedHobbies,
                  );

                  // Navigate to NextScreen
                  Navigator.push(
                      context,
                      MaterialPageRoute(
                          builder: (context) => const NextScreen()));
                }
              },
              child: const Text("Continue"),
            ),
          ],
        ),
      ),
    );
  }
}

class NextScreen extends StatelessWidget {
  const NextScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final userData = Provider.of<UserData>(context);

    return Scaffold(
      appBar: AppBar(title: const Text('User Details')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text("Name: ${userData.name}"),
            Text("ID: ${userData.id}"),
            Text("Gender: ${userData.gender}"),
            Text("Hobbies: ${userData.hobbies.join(', ')}"),
          ],
        ),
      ),
    );
  }
}
