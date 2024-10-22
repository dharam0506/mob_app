import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Routing Example',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyFormPage(),
    );
  }
}

class MyFormPage extends StatefulWidget {
  const MyFormPage({Key? key}) : super(key: key);

  @override
  State<MyFormPage> createState() => _MyFormPageState();
}

class _MyFormPageState extends State<MyFormPage> {
  final TextEditingController nameController = TextEditingController();
  final TextEditingController collegeController = TextEditingController();
  final TextEditingController courseController = TextEditingController();

  void submitForm() {
    String name = nameController.text;
    // Navigate to SuccessfulPage and pass the name as an argument
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => SuccessfulPage(name: name),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('My Form Page'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: nameController,
              decoration: const InputDecoration(labelText: 'Name'),
            ),
            TextField(
              controller: collegeController,
              decoration: const InputDecoration(labelText: 'College Name'),
            ),
            TextField(
              controller: courseController,
              decoration: const InputDecoration(labelText: 'Course Name'),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: submitForm,
              child: const Text('Submit'),
            ),
          ],
        ),
      ),
    );
  }
}

class SuccessfulPage extends StatelessWidget {
  final String name;

  const SuccessfulPage({Key? key, required this.name}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Success'),
      ),
      body: Center(
        child: Text(
          'Welcome, $name!',
          style: const TextStyle(fontSize: 24),
        ),
      ),
    );
  }
}
