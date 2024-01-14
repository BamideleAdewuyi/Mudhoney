/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MudhoneyAudioProcessorEditor::MudhoneyAudioProcessorEditor (MudhoneyAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(500, 700);
    setResizable(true, true);
    
    // Make combobox visible
    addAndMakeVisible(&boost);
    // Combobox options
    boost.addItem("Normal", 1);
    boost.addItem("Boost", 2);
    
    // Default option
    boost.setSelectedId(1);
    
    // Listener for combobox
    boost.addListener(this);
    
    // Add and make sliders visible
    addAndMakeVisible(&Gain);
    Gain.setSliderStyle(juce::Slider::Rotary);
//    Gain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 40, 40);
    Gain.setRange(0.0f, 1.0f, 0.001);
    Gain.addListener(this);

    addAndMakeVisible(&Level);
    Level.setSliderStyle(juce::Slider::Rotary);
    Level.setRange(0.0f, 1.0f, 0.001);
    Level.addListener(this);
    
    addAndMakeVisible(&Tone);
    Tone.setSliderStyle(juce::Slider::Rotary);
    Tone.setRange(0.0f, 1.0f, 0.001);
    Tone.addListener(this);
}

MudhoneyAudioProcessorEditor::~MudhoneyAudioProcessorEditor()
{
}

//==============================================================================
void MudhoneyAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::orange);

    g.setColour (juce::Colours::orange);
    g.setFont (15.0f);
}

void MudhoneyAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    boost.setBounds(200, 100, 100, 25);
    Gain.setBounds(30, 20, 200, 50);
    Level.setBounds(300, 20, 200, 50);
    Tone.setBounds(50, 200, 200, 50);
}

void MudhoneyAudioProcessorEditor::comboBoxChanged(juce::ComboBox * comboBoxThatHasChanged)
{
    audioProcessor.menuChoice = comboBoxThatHasChanged -> getSelectedId();
}

void MudhoneyAudioProcessorEditor::sliderValueChanged(juce::Slider *sliderThatHasChanged)
{
    if (&Gain == sliderThatHasChanged)
    {
        audioProcessor.gain = sliderThatHasChanged->getValue();
    }
    if (&Level == sliderThatHasChanged)
    {
        audioProcessor.level = sliderThatHasChanged->getValue();
    }
    if (&Tone == sliderThatHasChanged)
    {
        audioProcessor.tone = sliderThatHasChanged->getValue();
    }
}
