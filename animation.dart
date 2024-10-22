// Run this below cmd in terminal
// flutter pub add lottie

import 'package:flutter/material.dart';
import 'package:lottie/lottie.dart';

void main() {
  runApp(MaterialApp(
    home: MyApp(),
  ));
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> with SingleTickerProviderStateMixin {
  // Controller
  late final AnimationController _controller;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(
      duration:
          const Duration(seconds: 10), // Fixed typo from secods to seconds
      vsync: this,
    );
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  bool bookmark = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: GestureDetector(
          onTap: () {
            setState(() {
              // Added setState to update UI
              if (bookmark == false) {
                bookmark = true;
                _controller.forward();
              } else {
                bookmark = false;
                _controller.reverse();
              }
            });
          },
          child: Lottie.network(
            'https://assets9.lottieflies.com/packages/lf20_3le10jj4.json',
            controller: _controller,
            // Optional: Set the width and height for the animation
            width: 250,
            height: 250,
            fit: BoxFit.fill,
          ),
        ), // GestureDetector
      ), // Center
    ); // Scaffold
  }
}
