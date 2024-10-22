import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home: MyApp(),
  ));
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Using Asset Images'),
      ),
      body: Center(
        child: Image.asset(
          'assets/image.png', // Use your image path here
          height: 250,
          width: 250,
        ),
      ),
    );
  }
}