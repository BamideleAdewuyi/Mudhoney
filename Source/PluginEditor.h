/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MudhoneyAudioProcessorEditor  : public juce::AudioProcessorEditor,
// Listener for combobox and slider
private juce::ComboBox::Listener, juce::Slider::Listener
{
public:
    MudhoneyAudioProcessorEditor (MudhoneyAudioProcessor&);
    ~MudhoneyAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // Method for combobox to be able to change things
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatHasChanged) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MudhoneyAudioProcessor& audioProcessor;
    
    // Combobox for boost switch
    juce::ComboBox boost;
    
    // Sliders for gain, level and tone
    juce::Slider Gain;
    juce::Slider Level;
    juce::Slider Tone;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MudhoneyAudioProcessorEditor)
};
